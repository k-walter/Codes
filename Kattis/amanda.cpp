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

struct max_flow {
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
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

  ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
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

  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default colue is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll edmonds_karp(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      mf += f;                                   // if f > 0, add to mf
    }
    return mf;
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }
};

int ans=0; bool ok=1;
vector<vi> al(200001);
vi col(200001,-1);
vector<bool> vis(200001,0);
int dfs(int u) {
	if (vis[u]) return 0;
	vis[u]=1;
	int ans=0;
	ans += col[u];
	FORr(v,al[u]){
		if (col[v]!=-1) {
			if (col[v]==col[u]) ok=0;
		}
		else {
			col[v]=col[u]^1;
			ans += dfs(v);
		}
	}
	return ans;
}
ii dfs2(int u) {
	if (vis[u]) return {0,0};
	vis[u]=1;
	int L,R; L=R=0;
	if (col[u]) ++R;
	else ++L;
	FORr(v,al[u]){
		if (col[v]!=-1) {
			if (col[v]==col[u]) ok=0;
			continue;
		}
		col[v]=col[u]^1;
		const auto &[l,r] = dfs2(v);
		L+=l; R+=r;
	}
	return {L,R};
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("amanda.in", "r", stdin);

	int n,m; cin>>n>>m;
	while (m--) {
		int u,v,w; cin>>u>>v>>w;
		if (w==1) { al[u].pb(v); al[v].pb(u); continue; }
		int ww = (w==0) ? 0 : 1;
		if (col[u]==-1) { col[u]=ww; }
		else if (col[u]!=ww) { cout<<"impossible"; return 0; }
		if (col[v]==-1) { col[v]=ww; }
		else if (col[v]!=ww) { cout<<"impossible"; return 0; }
	}
	// greedy assign
	FOR(u,1,n+1){
		if (vis[u] or col[u]==-1) continue;
		ans += dfs(u);
		if (!ok){ cout<<"impossible"; return 0; }
	}
	// check odd cycle and assign
	FOR(u,1,n+1){
		if (vis[u] or col[u]!=-1) continue;
		col[u]=0;
		const auto &[l,r]=dfs2(u);
		if (!ok) { cout<<"impossible"; return 0; }
		ans+=min(l,r);
	}
	// FOR(u,1,n+1){
	// 	cout<<col[u]<<' ';
	// }
	cout<<ans;

	return 0;
}