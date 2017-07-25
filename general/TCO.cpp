// Tail call optimization
// !!! DO NOT USE !!!
// THIS IMPL IS CRAZY AND BUGGY!!!!!

template<typename Result>
class TCO {
  using NextFunc = std::function<TCO<Result>(void)>;

private:
  NextFunc next;
  bool done;
  Result result;

public:
  TCO(Result r)
    : done(true), result(r) {
  }

  TCO(NextFunc f)
    : next(f), done(false) {
  }

  Result get() {
    auto t = *this;
    forever {
      if (t.done) {
        return t.result;
      }
      t = t.next();
    }
  }
};
