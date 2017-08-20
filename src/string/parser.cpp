template<typename T> struct ParseResult {
  bool succeeded;
  T object;
  size_t pos;
  ParseResult(const bool succeeded, const T &object, const size_t pos) : succeeded(succeeded), object(object), pos(pos) {}
  friend std::ostream &operator<<(std::ostream &os, const ParseResult<T> &p) { return os << '{' << (p.succeeded ? "true" : "false") << ',' << p.object << ',' << p.pos << '}'; }
};

template<typename T> using Parser = std::function<ParseResult<T>(const std::string &, size_t)>;

Parser<std::string> token(std::string s) {
  const size_t n = s.size();
  return [n = std::move(n), s = std::move(s)](const std::string &target, const size_t pos) {
    if (target.size() < n) return ParseResult<std::string>(false, {}, pos);
    return target.substr(pos, n) == s ? ParseResult<std::string>(true, s, pos + n) : ParseResult<std::string>(false, {}, pos);
  };
}

template<typename T> Parser<T> operator||(Parser<T> p1, Parser<T> p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const size_t pos) {
    auto r = p1(target, pos);
    if (r.succeeded) return r;
    r = p2(target, pos);
    if (r.succeeded) return r;
    return ParseResult<T>(false, {}, pos);
  };
}

template<typename T1, typename T2> Parser<std::pair<T1, T2>> operator+(Parser<T1> p1, Parser<T2> p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const size_t pos) {
    auto r1 = p1(target, pos);
    if (!r1.succeeded) return ParseResult<std::pair<T1, T2>>(false, {}, pos);
    auto r2 = p2(target, r1.pos);
    if (!r2.succeeded) return ParseResult<std::pair<T1, T2>>(false, {}, pos);
    return ParseResult<std::pair<T1, T2>>(true, {r1.object, r2.object}, r2.pos);
  };
}

template<typename T1, typename T2> Parser<T2> operator>>(Parser<T1> p1, Parser<T2> p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const size_t pos) {
    auto r1 = p1(target, pos);
    if (!r1.succeeded) return ParseResult<T2>(false, {}, pos);
    auto r2 = p2(target, r1.pos);
    if (!r2.succeeded) return ParseResult<T2>(false, {}, pos);
    return ParseResult<T2>(true, r2.object, r2.pos);
  };
}

template<typename T1, typename T2> Parser<T1> operator<<(Parser<T1> p1, Parser<T2> p2) {
  return [p1 = std::move(p1), p2 = std::move(p2)](const std::string &target, const size_t pos) {
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
  return [d = std::move(d)](const std::string &target, const size_t pos) {
    if (target.size() <= pos) return ParseResult<char>(false, {}, pos);
    char c = target[pos];
    return d.count(c) ? ParseResult<char>(true, c, pos + 1) : ParseResult<char>(false, {}, pos);
  };
}

template<typename T, typename S, typename F> Parser<S> fmap(Parser<T> p, F &&f) {
  return [p = std::move(p), f = std::forward<F>(f)](const std::string &target, const size_t pos) {
    auto r = p(target, pos);
    return r.succeeded ? ParseResult<S>(true, f(r.object), r.pos) : ParseResult<S>(false, {}, r.pos);
  };
}

template<typename T, typename F> Parser<T> lazy(const F &f) {
  bool instantiated = false;
  Parser<T> p;
  Parser<T> &&q = [f = std::move(f), p = std::move(p), instantiated = std::move(instantiated)](const std::string &target, const size_t pos) mutable {
    if (!instantiated) {
      p = f();
      instantiated = true;
    }
    return p(target, pos);
  };
  return [q = std::make_shared<Parser<T>>(std::move(q))](const std::string &target, const size_t pos) { return (*q)(target, pos); };
}
