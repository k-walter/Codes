#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORr(a, x) for (auto& a : x)
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef tuple<int,int> ii;
typedef tuple<int,int,int> iii;
typedef tuple<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef tuple<int,ll,ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vdit;
const ll INF = 1e18;

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

  inline vi get_S(int s) {
    vi ans; ans.push_back(s);
    vector<bool> vis(V, 0); vis[s]=1;
    queue<int> q; q.push(s);
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

  inline vi get_T(int s) {
    vector<bool> vis(V, 0); vis[s]=1;
    queue<int> q; q.push(s);
    while (q.size()) {
      const int &u = q.front();
      for (int &i : AL[u]) {
        auto &[v,c,f] = EL[i];
        if (vis[v] or c == f) continue;
        vis[v]=1; q.push(v);
      }
      q.pop();
    }
    vi ans;
    for (int u = 0; u < V; ++u)
      if (AL[u].size() and !vis[u]) ans.push_back(u);
    return ans;
  }

  inline vii get_cut(int s) {
    vii ans;
    vector<bool> vis(V, 0);
    queue<int> q;
    q.push(s); vis[s]=1;
    while (q.size()) {
      const int &u = q.front();
      for (int &i : AL[u]) {
        auto &[v,c,f] = EL[i];
        if (vis[v] or c==0) continue;
        if (c==f) { ans.emplace_back(u,v); continue; }
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

  inline vii get_match(int S) {
    vii ans;
    for (auto &[_,u] : get_cut(S)){
      for (int &i: AL[u]) {
        auto &[v,c,f] = EL[i];
        if (c==0 or f==0) continue;
        ans.emplace_back(u,v);
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

int n,m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("paintball.in", "r", stdin);

	cin>>n>>m;
	max_flow mf(1+n+n+1);
	while (m--) {
		int u,v; cin>>u>>v;
		mf.add_edge(u, v+n, 1);
		mf.add_edge(v, u+n, 1);
	}
	FOR(u, 1, n+1) {
		mf.add_edge(0, u, 1);
		mf.add_edge(u+n, 2*n+1, 1);
	}
	if (mf.dinic(0, 2*n+1) != n) {
		cout<<"Impossible"; return 0;
	}
	for (auto &[u,v]:mf.get_match(0)) {
		cout<<v-n<<"\n";
	}

	return 0;
}

/*
each person killed by one bullet

*/