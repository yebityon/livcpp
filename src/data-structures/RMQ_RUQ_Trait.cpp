template<typename T, T upperInf = std::numeric_limits<T>::max()> struct RMQ_RUQ_Trait {
  using FoldMonoid = minMonoid<T, upperInf>;
  using ActionMonoid = updateMonoid<T>;
  typename FoldMonoid::value_type apply(typename FoldMonoid::value_type t, typename ActionMonoid::value_type q) { return q.first ? q.second : t; }
};
