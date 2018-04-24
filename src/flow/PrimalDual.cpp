using Flow = int;
using Cost = int;
class PrimalDual {
public:
  struct Edge {
    int d;
    Flow c, f;
    Cost w;
    int r;
    Edge(int d, Flow c, Flow f, Cost w, int r) : d(d), c(c), f(f), w(w), r(r) {}
  };

  int n;
  vector<vector<Edge>> g;
  PrimalDual(int n) : n(n), g(n) {}

  void addEdge(int src, int dst, Flow cap, Cost cost) { // 有向辺
    int rsrc = g[dst].size();
    int rdst = g[src].size();
    g[src].emplace_back(dst, cap, 0, cost, rsrc);
    g[dst].emplace_back(src, cap, cap, -cost, rdst);
  }

  template<Cost inf = numeric_limits<Cost>::max() / 8> Cost solve(int s, int t, Flow f) {
    Cost res = 0;
    vector<Cost> h(n), dist(n);
    vector<int> prevv(n), preve(n);

    using state = pair<Cost, int>;
    priority_queue<state, vector<state>, greater<state>> q;
    fill(h.begin(), h.end(), 0);
    while (f > 0) {
      fill(dist.begin(), dist.end(), inf);
      dist[s] = 0;
      q.emplace(0, s);
      while (q.size()) {
        Cost cd;
        int v;
        tie(cd, v) = q.top();
        q.pop();
        if (dist[v] < cd) continue;
        for (int i = 0; i < g[v].size(); ++i) {
          const Edge &e = g[v][i];
          if (residue(e) == 0) continue;
          if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
            dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
            prevv[e.d] = v;
            preve[e.d] = i;
            q.emplace(dist[e.d], e.d);
          }
        }
      }

      if (dist[t] == inf) return -1;

      for (int i = 0; i < n; ++i) h[i] += dist[i];
      Flow d = f;
      for (int v = t; v != s; v = prevv[v]) cmin(d, residue(g[prevv[v]][preve[v]]));
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        Edge &e = g[prevv[v]][preve[v]];
        e.f += d;
        g[v][e.r].f -= d;
      }
    }
    return res;
  }

  Flow residue(const Edge &e) { return e.c - e.f; }
};
