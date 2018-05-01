vector<int> subtreeSizes(const Graph &rootedTree, const int &root = 0) {
  vector<int> sizes(rootedTree.size());
  function<int(int)> dfs = [&](const int &v) {
    int cnt = 1;
    for (auto &e : rootedTree[v]) cnt += dfs(e.dst);
    sizes[v] = cnt;
    return cnt;
  };
  dfs(root);
  return sizes;
}