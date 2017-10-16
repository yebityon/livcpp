using Flow = int;
struct FlowEdge {
  int src, dst, rev;
  Flow cap;
  FlowEdge(const int s = 0, const int d = 0, const Flow c = 0, const int r = 0) : src(s), dst(d), cap(c), rev(r) {}
};

using FlowEdges = std::vector<FlowEdge>;

class FlowGraph {
  std::vector<FlowEdges> g;

public:
  FlowGraph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  FlowEdges &operator[](const int i) & { return g[i]; }

  void addEdge(const int src, const int dst, const Flow c = 1) {
    g[src].emplace_back(src, dst, c, g[dst].size());
    g[dst].emplace_back(dst, src, 0, g[src].size() - 1);
  }
};
