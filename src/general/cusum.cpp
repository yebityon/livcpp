template<typename OutputIterator> void cusum(OutputIterator first, OutputIterator last) {
  OutputIterator prev = first;
  while (first != last) {
    *(++first) += *prev;
    prev = first;
  }
}
