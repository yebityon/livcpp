/* Find the minimum x∈(low, up] such that f(x) is true
        *--- (true)
    ----     (false)
*/
template<typename F> int binarySearchU(int low, int up, const F &f) {
  while (up - low > 1) {
    int mid = low + (up - low) / 2;
    (f(mid) ? up : low) = mid;
  }
  return up;
}
