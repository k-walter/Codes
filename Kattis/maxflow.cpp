#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int,int> ii;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll INF = 1e18;                             // large enough

class max_flow {
public:
  int V;
  vector<edge> EL;
  vector<vi> AL, AM;
  vi d, last;
  vector<ii> p;

  inline bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  inline ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  inline ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

  inline ll edmonds_karp(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      mf += f;                                   // if f > 0, add to mf
    }
    return mf;
  }

  inline ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }

  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
    // AM.assign(V, vi(V, -1));    // Comment out if not using
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  inline void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    AL[u].push_back(EL.size());                // remember this index
    // AM[u][v] = EL.size();                       // comment out if not using
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0

    AL[v].push_back(EL.size());                // remember this index
    // AM[v][u] = EL.size();                       // comment out if not using
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
  }

  inline edge& get_edge(int u, int v) {
    return EL[AM[u][v]];
  }

  inline ll& get_flow(int u, int v) {
    return get<2>(get_edge(u,v));
  }

  inline ll& get_cap(int u, int v) {
    return get<1>(get_edge(u,v));
  }

  inline vi& get_ST(int st) {
    vi ans;
    vector<bool> vis(V, 0);
    queue<int> q;
    q.push(st); vis[st]=1;
    while (q.size()) {
      const int &u = q.front();
      for (int &i : AL[u]) {
        auto &[v,c,f] = EL[i];
        if (vis[v] or c == f) continue;
        vis[v]=1; q.push(v); ans.push_back(v);
      }
      q.pop();
    }
    return ans;
  }

  inline vii& get_cut(int st) {
    vii ans;
    vector<bool> vis(V, 0);
    queue<int> q;
    q.push(st); vis[st]=1;
    while (q.size()) {
      const int &u = q.front();
      for (int &i : AL[u]) {
        auto &[v,c,f] = EL[i];
        if (vis[v] or c==f) { ans.emplace_back(u,v); continue; }
        vis[v]=1; q.push(v);
      }
      q.pop();
    }
    return ans;
  }

  inline vector<tuple<int,int,ll>> get_path() {
    vector<tuple<int,int,ll>> ans;
    for (int u = 0; u < V; ++u) {
      for (int &i: AL[u]) {
        auto &[v,c,f] = EL[i];
        if (c==0 or f==0) continue;
        ans.emplace_back(u,v,f);
      }
    }
    return ans;
  }

  inline void set_cap(int u, int v, ll cap) {
    get_cap(u,v) = cap;
  }

  inline void reset_flow(ll f=0) {
    for (auto &[v,cap,flow]:EL) flow = f;
  }
};

int main() {
  freopen("maxflow.in", "r", stdin);
  cin.tie(NULL); cout.tie(NULL);

  int V, E, s, t; cin>>V>>E>>s>>t;
  cout<<V<<" ";
  max_flow mf(V);
  while (E--) {
    int u, v, w; cin>>u>>v>>w;
    mf.add_edge(u, v, w);
  }
  cout<<mf.dinic(s,t)<<" ";
  const auto &ans = mf.get_path();
  cout<<ans.size()<<"\n";
  for (auto &[u,v,f]:ans) cout<<u<<" "<<v<<" "<<f<<"\n";

  return 0;
}
