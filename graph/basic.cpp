using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int &s = 0, const int &d = 0, const Weight &w = 0)
    : src(s), dst(d), weight(w) {
  }
};

using Edges  = std::vector<Edge>;
using Array  = std::vector<Weight>;
using Matrix = std::vector<Array>;

class Graph {
  std::vector<Edges> g;

public:
  // clang-format off
  Graph(const int &size = 0) : g(size) { }

  void addArc(const int &src, const int &dst, const Weight &w = 1) {
    g[src].emplace_back(src, dst, w);
  }

  void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }

  Graph toRootedTree(int r);
  std::vector<Weight> dijkstra(const int &src, const int &inf);
  Matrix warshallFloyd(const int &inf);
  std::pair<Weight, Edges> prim(const int &r);
  template<typename UnionFind> std::pair<Weight, Edges> kruskal();
  // clang-format on
};
