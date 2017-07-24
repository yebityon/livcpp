template<typename F>
int binarySearch(int low, int high, const F &f) {
  while (high - low > 1) {
    int mid                  = low + (high - low) / 2;
    *(f(mid) ? &low : &high) = mid;
  }
  return low;
}
