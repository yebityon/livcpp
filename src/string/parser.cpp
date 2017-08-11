template<typename T> struct ParseResult {
  bool succeeded;
  T object;
  int pos;
  ParseResult(const bool succeeded, const T &object, const int pos) : succeeded(succeeded), object(object), pos(pos) {}
  friend std::ostream &operator<<(std::ostream &os, const ParseResult<T> &p) { return os << '{' << (p.succeeded ? "true" : "false") << ',' << p.object << ',' << p.pos << '}'; }
};

template<typename T> using Parser = std::function<ParseResult<T>(std::string, int)>;

Parser<std::string> token(const std::string &s) {
  const int n = s.size();
  return [n = std::move(n), s = std::move(s)](const std::string &target, const int pos) {
    if (target.size() < n) return ParseResult<std::string>(false, {}, pos);
    return target.substr(pos, n) == s ? ParseResult<std::string>(true, s, pos + n) : ParseResult<std::string>(false, {}, pos);
  };
}

template<typename T> Parser<T> operator||(const Parser<T> &p1, const Parser<T> &p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const int pos) {
    auto r = p1(target, pos);
    if (r.succeeded) return r;
    r = p2(target, pos);
    if (r.succeeded) return r;
    return ParseResult<T>(false, {}, pos);
  };
}

template<typename T1, typename T2> Parser<std::pair<T1, T2>> operator+(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const int pos) {
    auto r1 = p1(target, pos);
    if (!r1.succeeded) return ParseResult<std::pair<T1, T2>>(false, {}, pos);
    auto r2 = p2(target, r1.pos);
    if (!r2.succeeded) return ParseResult<std::pair<T1, T2>>(false, {}, pos);
    return ParseResult<std::pair<T1, T2>>(true, {r1.object, r2.object}, r2.pos);
  };
}

template<typename T1, typename T2> Parser<T2> operator>>(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const int pos) {
    auto r1 = p1(target, pos);
    if (!r1.succeeded) return ParseResult<T2>(false, {}, pos);
    auto r2 = p2(target, r1.pos);
    if (!r2.succeeded) return ParseResult<T2>(false, {}, pos);
    return ParseResult<T2>(true, r2.object, r2.pos);
  };
}

template<typename T1, typename T2> Parser<T1> operator<<(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const int pos) {
    auto r1 = p1(target, pos);
    if (!r1.succeeded) return ParseResult<T1>(false, {}, pos);
    auto r2 = p2(target, r1.pos);
    if (!r2.succeeded) return ParseResult<T1>(false, {}, pos);
    return ParseResult<T1>(true, r1.object, r2.pos);
  };
}

Parser<char> oneOf(const std::string &s) {
  std::unordered_set<char> d;
  for (auto &c : s) d.insert(c);
  return [d = std::move(d)](const std::string &target, const int pos) {
    if (target.size() <= pos) return ParseResult<char>(false, {}, pos);
    char c = target[pos];
    return d.count(c) ? ParseResult<char>(true, c, pos + 1) : ParseResult<char>(false, {}, pos);
  };
}

template<typename T> Parser<vector<T>> many(const Parser<T> &p) {
  return [p = std::move(p)](const std::string &target, int pos) {
    vector<T> rs;
    for (;;) {
      auto r = p(target, pos);
      if (!r.succeeded) break;
      rs.push_back(std::move(r.object));
      pos = r.pos;
    }
    return ParseResult<vector<T>>(true, std::move(rs), pos);
  };
}

template<typename T, typename S> Parser<pair<vector<T>, vector<S>>> manySep(const Parser<T> &p1, const Parser<S> &p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, int pos) {
    vector<T> rs1;
    vector<S> rs2;
    {
      auto r = p1(target, pos);
      if (!r.succeeded) ParseResult<pair<vector<T>, vector<S>>>(true, {std::move(rs1), std::move(rs2)}, pos);
      rs1.push_back(std::move(r.object));
      pos = r.pos;
    }
    for (auto p = p2 + p1;;) {
      auto r = p(target, pos);
      if (!r.succeeded) break;
      rs2.push_back(std::move(r.object.first));
      rs1.push_back(std::move(r.object.second));
      pos = r.pos;
    }
    return ParseResult<pair<vector<T>, vector<S>>>(true, {std::move(rs1), std::move(rs2)}, pos);
  };
}

template<typename T, typename S, typename F> Parser<S> fmap(const Parser<T> &p, const F &f) {
  return [p = std::move(p), f = std::move(f)](const std::string &target, const int pos) {
    auto r = p(target, pos);
    return r.succeeded ? ParseResult<S>(true, f(r.object), r.pos) : ParseResult<S>(false, {}, r.pos);
  };
}

template<typename T, typename F> Parser<T> lazy(const F &f) {
  bool instantiated = false;
  Parser<T> p;
  return [f = std::move(f), p = std::move(p), instantiated = std::move(instantiated)](const std::string &target, const int pos) mutable {
    if (!instantiated) {
      p = f();
      instantiated = true;
    }
    return p(target, pos);
  };
}
