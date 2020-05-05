#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("shortestpath1.in", "r", stdin);

	int n,m,q,s;
	while (cin>>n>>m>>q>>s, !(n==0&&m==0&&q==0&&s==0)) {
		vector<vii> al(n);
		while (m--) {
			int u,v,w; cin>>u>>v>>w;
			al[u].emplace_back(v,w);
		}

		// SSSP
		vector<int> dist(n, INF); dist[s] = 0;
		// set<ii> pq; pq.emplace(0, s);
		priority_queue<ii, vii, greater<ii>> pq; pq.emplace(0,s);
		while (!pq.empty()) {
			// auto it = pq.begin();
			// auto [d,u] = *it; pq.erase(it);
			auto [d,u] = pq.top(); pq.pop();
			if (d > dist[u]) continue;
			for (auto &[v,w] : al[u]) {
				if (d+w >= dist[v]) continue;
				// pq.erase({dist[v], v});
				dist[v] = d + w;
				pq.emplace(dist[v], v);
			}
		}

		while (q--) {
			int v; cin>>v;
			if (dist[v] == INF) cout << "Impossible\n";
			else cout << dist[v] << "\n";
		}
		cout << "\n";
	}
	return 0;
}