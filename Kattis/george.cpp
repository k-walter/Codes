#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;
const int INF = 1e9;

vector<vii> am;

int free(int &u, int &v, int &t) {
	auto &[t0,t1] = am[u][v];
	if (t<t0 || t>=t1) return t;
	return t1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("george.in", "r", stdin);

	int n,m,s,t,k,g; cin>>n>>m>>s>>t>>k>>g;
	--s; --t;
	vector<int> george;
	vector<vii> al(n);
	am.assign(n, vii(n));

	while (g--) { int u; cin>>u; george.emplace_back(u-1); }
	while (m--) {
		int u,v,w; cin>>u>>v>>w; --u; --v;
		al[u].emplace_back(v,w);
		al[v].emplace_back(u,w);
		am[u][v].second = -w; // to prevent clash
		am[v][u].second = -w;
	}

	// George's path
	int st = 0;
	for (int i = 1; i < george.size(); ++i) {
		const int &u = george[i-1], &v = george[i];
		const auto &[_,w] = am[u][v];
		am[u][v] = {st, st-w}; // since w is -ve
		am[v][u] = {st, w}; // since w incremented
		st = w;
		// cout << "george traveling from " << u << " to " << v << " from " << am[u][v].first << " to " << am[v][u].second << "\n";
	}

	vector<int> dist(n, INF); dist[s] = k;
	priority_queue<ii, vii, greater<ii>> pq; pq.emplace(k,s);
	while (pq.size()) {
		auto [d,u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		// cout << "visiting " << u << " with distance " << d <<"\n";
		if (d == t) break;
		for (auto &[v,w] : al[u]) {
			if (w+free(u,v,d) >= dist[v]) continue;
			dist[v] = w+free(u,v,d);
			pq.emplace(dist[v], v);
		}
	}

	cout << dist[t] - k;


	return 0;
}