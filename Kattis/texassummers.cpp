#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using ii = pair<int,int>;

int square(const int &a) { return a*a; }
int weight(const ii &a, const ii &b) {
	return square(a.first-b.first) + square(a.second-b.second);
}

int n;
vector<int> parent;
void rec(const int &i) {
	if (parent[i] == n-2) return;
	rec(parent[i]);
	cout << parent[i] << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("texassummers.in", "r", stdin);

	cin>>n; n+=2;
	vector<ii> pts;
	int x,y;
	for (int i = 0; i < n; ++i) {
		cin>>x>>y;
		pts.emplace_back(x,y);
	}

	parent.resize(n);
	vector<int> dist(n,INF); dist[n-2] = 0;
	set<ii>pq; pq.emplace(0, n-2); // lazy delete gets too slow
	while (pq.size()) {
		auto it = pq.begin();
		auto [d,u] = *it; pq.erase(it);
		if (u == n-1) break;
		for (int v = 0; v < n; ++v) {
			if (d + weight(pts[u],pts[v]) >= dist[v] || v == u) continue;
			pq.erase({dist[v], v});
			// dist[v] = d + weight(pts[u],pts[v]);
			dist[v] = d + am[u][v];
			parent[v] = u;
			pq.emplace(dist[v], v);
		}
	}

	if (parent[n-1] == n-2) cout << '-';
	else rec(n-1);

	return 0;
}