#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;
using li = pair<long long,int>;
using vii = vector<ii>;
const int INF = 1e9;

vector<int> parent;
void rec(const int &i) {
	if (parent[i] == 0) return;
	rec(parent[i]);
	cout << parent[i] << " ";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("detour.in", "r", stdin);

	int n,m; cin>>n>>m;
	vector<vii> al(n);
	while (m--) {
		int a,b,d; cin>>a>>b>>d;
		al[a].emplace_back(b,d);
		al[b].emplace_back(a,d);
	}

	// Find SSSP to all
	vector<int> path(n);
	vector<int> dist(n,INF); dist[1] = 0;
	set<ii> pq; pq.emplace(0,1); // dist 0, node 1
	while (pq.size()) {
		auto it = pq.begin();
		const auto [d,u] = *it; pq.erase(it);
		for (const auto &[v,w] : al[u]) {
			if (d+w < dist[v]) {
				pq.erase({dist[v], v});
				dist[v] = d+w; path[v] = u;
				pq.emplace(dist[v], v);
			}
		}
	}

	// DFS remaining paths
	parent.resize(n);
	bool visit[n] = {false}; visit[0] = true;
	vector<ii> s; s.emplace_back(0,1); // from 0, #vtx 1
	while (s.size()) {
		auto [u,d] = s.back(); s.pop_back(); // dfs
		for (auto &[v,w] : al[u]) {
			if (v == path[u] || visit[v]) continue;
			parent[v] = u;
			if (v == 1) {
				cout << d+1 << " " << 0 << " ";
				rec(1); cout << 1;
				return 0;
			}
			visit[v] = true;
			s.emplace_back(v,d+1);
		}
	}
	cout << "impossible";

	return 0;
}