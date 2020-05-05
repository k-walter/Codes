#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
const int INF = 1e9;

int v,u,w,s,t,k;
vector<vii> al;
vector<vi> dist;

void dijkstra() {
	priority_queue<iii, viii, greater<iii>> pq; // faster
	dist.clear(); dist.assign(v, vi(k, INF));
	dist[s].assign(k, 0); pq.emplace(0,0,s);
	while (pq.size()) {
		auto [d,kk,u] = pq.top(); pq.pop();
		if (d > dist[u][kk]) continue;
		// cout << "visiting " << u << " with distance " << d << " and " << kk << " jumps\n";
		++kk;

		if (u == t) return;

		for (const auto &[v,w] : al[u]) { // neighbours
			if (d+w>=dist[v][kk]) continue;
			
			dist[v][kk] = d+w;
			if (kk >= k-1) continue;
			
			pq.emplace(d+w, kk, v);
			for (int i = kk+1; i < k && dist[v][kk] < dist[v][i]; ++i) // higher steps
				dist[v][i] = dist[v][kk];
			// cout << "adding " << dist[v][kk] << " " << kk << " " << v << "\n";
		}

		// for (auto &i : dist) {
		// 	for (auto &j : i)
		// 		cout << j << " ";
		// 	cout << "\n";
		// }
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("shortestpath4.in", "r", stdin);

	int tc; cin>>tc; cin.get();
	while (tc--) {
		cin>>v;
		al.clear(); al.resize(v);
		for (auto &i : al) {
			int x; cin>>x;
			while (x--) {
				cin>>u>>w;
				i.emplace_back(u,w);
			}
		}

		int q; cin>>q;
		while (q--) {
			cin>>s>>t>>k;
			if (k == 1) { cout << -1 << "\n"; continue; }

			dijkstra();
			int &ans = dist[t][k-1];
			if (ans == INF) ans = -1;
			cout << ans << "\n";
		}
		cout << "\n";
	}

	return 0;
}