using Flow = int;
struct FlowEdge {
  int src, dst;
  Flow cap;
  int rev;
  FlowEdge(const int s = 0, const int d = 0, const Flow c = 0, const int r = 0) : src(s), dst(d), cap(c), rev(r) {}
};

using FlowEdges = vector<FlowEdge>;

class FlowGraph {
  vector<FlowEdges> g;
  using iterator = vector<FlowEdges>::iterator;
  using const_iterator = vector<FlowEdges>::const_iterator;

public:
  FlowGraph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  FlowEdges &operator[](const int i) & { return g[i]; }

  void addEdge(const int src, const int dst, const Flow c = 1) {
    g[src].emplace_back(src, dst, c, g[dst].size());
    g[dst].emplace_back(dst, src, 0, g[src].size() - 1);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};
