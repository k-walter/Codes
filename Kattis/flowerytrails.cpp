#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using ii = pair<int,int>;
set<ii> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("flowerytrails.in", "r", stdin);

	int p,t; cin>>p>>t;
	vector<vector<ii>> al(p);
	while (t--) {
		int p1,p2,l; cin>>p1>>p2>>l;
		al[p1].emplace_back(p2,l);
		al[p2].emplace_back(p1,l);
	}

	int tot = 0;
	vector<vector<ii>> path(p);
	vector<int> dist(p, INF); dist[0]=0;
	for (int i = 0; i < p; ++i)
		pq.emplace(INF,i);
	while (pq.size()) {
		const auto &it = pq.begin();
		const auto [d,u] = *it; pq.erase(it);
		if (u == p-1) break;
		for (const auto &[v,w] : al[u]) {
			if (dist[u]+w > dist[v]) continue;
			if (dist[u]+w == dist[v])
				path[v].emplace_back(u,w);
			else {
				path[v].clear(); path[v].emplace_back(u,w);
				pq.erase({dist[v], v});
				dist[v] = dist[u]+w;
				pq.emplace(dist[v], v);
			}
		}
	}

	bool visit[p] = {false}; visit[p-1] = true;
	vector<int> s = {p-1};
	while (s.size()) {
		int u = s.back(); s.pop_back();
		for (auto &[v,w] : path[u]) {
			// cout << u << " comes from " << v << " with " << w << "\n";
			tot += w;
			if (!visit[v]) {
				visit[v] = true;
				s.push_back(v);
			}
		}
	}
	cout << 2*tot << "\n";

	return 0;
}