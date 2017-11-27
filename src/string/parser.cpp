class Source {
  using iterator = std::string::iterator;
  using const_iterator = std::string::const_iterator;
  const_iterator begin, s;

public:
  Source(iterator s) : begin(s), s(s) {}
  Source(const_iterator s) : begin(s), s(s) {}

  char peek() {
    char ch = *s;
    if (!ch) throw ex("too short");
    return ch;
  }

  void next() {
    peek();
    ++s;
  }

  std::string ex(const std::string &e) {
    std::ostringstream oss;
    oss << "[pos: " << s - begin << ", char: " << *s << "] " << e << '\n';
    return oss.str();
  }

  bool operator==(const Source &t) const { return s == t.s; }
  bool operator!=(const Source &t) const { return !(*this == t); }
};

template<typename T> using Parser = std::function<T(Source &)>;

Parser<char> satisfy(const std::function<bool(char)> &f) {
  return [=](Source &s) {
    char c = s.peek();
    if (!f(c)) throw s.ex("not satisfy");
    s.next();
    return c;
  };
}

template<typename T> Parser<T> left(const std::string &e) {
  return [=](Source &s) -> T { throw s.ex(e); };
}

Parser<char> left(const std::string &e) { return left<char>(e); }

template<typename T1, typename T2> Parser<std::string> operator+(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [=](Source &s) {
    std::string r;
    r += p1(s);
    r += p2(s);
    return r;
  };
}

template<typename T> Parser<std::string> operator*(int n, const Parser<T> &p) {
  return [=](Source &s) {
    std::string r;
    rep(i, n) r += p(s);
    return r;
  };
}
template<typename T> Parser<std::string> operator*(const Parser<T> &x, int n) { return n * x; }

template<typename T> Parser<std::string> many_str(const Parser<T> &p) {
  return [=](Source &s) {
    std::string r;
    try {
      for (;;) r += p(s);
    } catch (const std::string &) {}
    return r;
  };
}

Parser<std::string> many(const Parser<char> &p) { return many_str(p); }
Parser<std::string> many(const Parser<std::string> &p) { return many_str(p); }
template<typename T> Parser<std::list<T>> many(const Parser<T> &p) {
  return [=](Source &s) {
    std::list<T> v;
    try {
      for (;;) v.emplace_back(p(s));
    } catch (const std::string &) {}
    return v;
  };
}

template<typename T> Parser<std::string> many1(const Parser<T> &p) { return p + many(p); }

template<typename T> const Parser<T> operator||(const Parser<T> &p1, const Parser<T> &p2) {
  return [=](Source &s) {
    T r;
    Source back = s;
    try {
      r = p1(s);
    } catch (const std::string &) {
      if (s != back) throw;
      r = p2(s);
    }
    return r;
  };
}

template<typename T1, typename T2> Parser<T1> operator<<(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [=](Source &s) {
    T1 r = p1(s);
    p2(s);
    return r;
  };
}

template<typename T1, typename T2> Parser<T2> operator>>(const Parser<T1> &p1, const Parser<T2> &p2) {
  return [=](Source &s) {
    p1(s);
    return p2(s);
  };
}

template<typename T> Parser<T> tryp(const Parser<T> &p) {
  return [=](Source &s) {
    T r;
    Source bak = s;
    try {
      r = p(s);
    } catch (const std::string &) {
      s = bak;
      throw;
    }
    return r;
  };
}

template<typename T1, typename T2> Parser<T2> fmap(const std::function<T2(const T1 &)> &f, const Parser<T1> &p) {
  return [=](Source &s) { return f(p(s)); };
}

template<typename L, typename R, typename X> Parser<std::function<X(const L &)>> fmap(const std::function<X(const L &, const R &)> &f, const Parser<R> &p) {
  return [=](Source &s) {
    R r = p(s);
    return [=](const L &l) { return f(l, r); };
  };
}

Parser<std::function<int(int)>> fmap(const std::function<int(int, int)> &f, const Parser<int> &p) { return fmap<int, int, int>(f, p); }

Parser<int> eval(const Parser<int> &p, const Parser<std::list<std::function<int(int)>>> &fs) {
  return [=](Source &s) {
    int x = p(s);
    auto xs = fs(s);
    return std::accumulate(xs.begin(), xs.end(), x, [](int a, const std::function<int(int)> &f) { return f(a); });
  };
}

auto anyChar = satisfy([](char) { return true; });

Parser<char> char1(char c) {
  return satisfy([=](char x) { return x == c; }) || left(std::string("not char '") + c + "'");
}

auto digit = satisfy([](char c) { return '0' <= c && c <= '9'; }) || left("not digit");
auto upper = satisfy([](char c) { return 'A' <= c && c <= 'Z'; }) || left("not upper");
auto lower = satisfy([](char c) { return 'a' <= c && c <= 'z'; }) || left("not lower");
auto alpha = satisfy([](char c) { return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'); }) || left("not alpha");
auto alphaNum = satisfy([](char c) { return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'); }) || left("not alphaNum");

Parser<std::string> token(const std::string &xs) {
  return [=](Source &s) {
    for (auto x : xs) (char1(x) || left("not token \"" + xs + "\""))(s);
    return xs;
  };
}
