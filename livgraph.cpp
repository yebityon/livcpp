namespace livgraph {
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
    Graph(const int &size = 0)
      : g(size) {
    }

    void addArc(const int &src, const int &dst, const Weight &w = 1) {
      g[src].emplace_back(src, dst, w);
    }

    void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
      addArc(node1, node2, w);
      addArc(node2, node1, w);
    }

    std::vector<Weight> dijkstra(const int &src, const int &inf = std::numeric_limits<Weight>::max() / 8) {
      using state = std::pair<Weight, int>;
      std::priority_queue<state, std::vector<state>, std::greater<state>> q;
      std::vector<Weight> dist(g.size(), inf);
      dist[src] = 0;
      q.emplace(0, src);
      while (q.size()) {
        Weight d;
        int v;
        std::tie(d, v) = q.top();
        q.pop();
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
          if (cmin(dist[e.dst], dist[v] + e.weight)) {
            q.emplace(dist[e.dst], e.dst);
          }
        }
      }
      return dist;
    }

    Matrix warshallFloyd(const int &inf = std::numeric_limits<Weight>::max() / 8) {
      int n = g.size();
      Matrix d(n, Array(n, inf));
      rep(i, n) d[i][i] = 0;
      rep(i, n) for (auto &e : g[i]) cmin(d[e.src][e.dst], e.weight);
      rep(k, n) rep(i, n) rep(j, n) {
        if (d[i][k] != inf && d[k][j] != inf) cmin(d[i][j], d[i][k] + d[k][j]);
      }
      return d;
    }

    std::pair<Weight, Edges> prim(const int &r = 0) {
      struct comp {
        bool operator()(const Edge &e, const Edge &f) const {
          return e.weight > f.weight;
        }
      };
      Edges tree;
      Weight total = 0;
      std::vector<int> vs(g.size());
      std::priority_queue<Edge, std::vector<Edge>, comp> q;
      q.emplace(-1, r, 0);
      while (q.size()) {
        Edge e = q.top();
        q.pop();
        if (vs[e.dst]) continue;
        vs[e.dst] = true;
        total += e.weight;
        if (e.src != -1) tree.emplace_back(e);
        for (auto &f : g[e.dst]) {
          if (!vs[f.dst]) q.emplace(f);
        }
      }
      return std::make_pair(total, tree);
    }

    template<typename UnionFind>
    std::pair<Weight, Edges> kruskal() {
      UnionFind uf(g.size());
      Edges es;
      for (auto &adj : g) {
        for (auto &e : adj) es.emplace_back(e);
      }
      std::sort(es.begin(), es.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
      Weight total = 0;
      Edges tree;
      for (auto &e : es) {
        if (!uf.same(e.src, e.dst)) {
          tree.pb(e);
          total += e.weight;
          uf.unite(e.src, e.dst);
        }
      }
      return std::make_pair(total, tree);
    }
  };
}
