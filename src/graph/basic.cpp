using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s = 0, const int d = 0, const Weight w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = vector<Edge>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

class Graph {
  vector<Edges> g;
  using iterator = vector<Edges>::iterator;
  using const_iterator = vector<Edges>::const_iterator;

public:
  Graph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int i) const { return g[i]; }
  void addArc(const int src, const int dst, const Weight w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int node1, const int node2, const Weight w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};
