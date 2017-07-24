// Find the maximum x∈[low, up) such that f(x) is true
template<typename F>
int binarySearch(int low, int up, const F &f) {
  while (up - low > 1) {
    int mid             = low + (up - low) / 2;
    (f(mid) ? low : up) = mid;
  }
  return low;
}
