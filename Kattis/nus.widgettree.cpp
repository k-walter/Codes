#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m,VIS;
vector<vii> al;
vector<int> dist, d2;
vector<int> vis;

inline int dfs(int u) {
	if (vis[u] == 2) return dist[u];
	if (vis[u] == 1) return -1;
	int &dd = dist[u]; ++dd;
	vis[u] = 1;
	for (auto &[v,w] : al[u]) {
		int d = dfs(v);
		if (d == -1) return d;
		d = ((ll)d * w) % m;
		dd = (d + dd) % m;
	}
	vis[u] = 2;
	return dd;
}

inline int dfs2(int u) {
	// cout << "at " << u << "\n";
	if (vis[u] == VIS) return d2[u];
	vis[u] = VIS;
	int &dd = d2[u]; dd = -1;
	for (auto &[v,w] : al[u]) {
		int d = dfs2(v);
		if (d == -1) continue;
		if (dd == -1) dd = 1;
		d = ((ll)d * w) % m;
		dd = (d + dd) % m;
	}
	// cout << "vtx " << u << " dist " << dd << "\n";
	return dd;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.widgettree.in", "r", stdin);

	cin>>n>>m;
	al.resize(n);
	dist.resize(n);
	vis.resize(n);
	// save AL
	int v;
	for (vii &adj : al) {
		cin >> n;
		while (n--) {
			cin >> v;
			if (dist[v]++) continue;
			adj.emplace_back(v, 0);
		}
		for (auto &[v,w] : adj) {
			w = dist[v];
			dist[v] = 0;
		}
	}
	// find cycle, calculate size
	if (dfs(0) == -1) {
		cout << "Invalid";
		return 0;
	}
	// 0
	int t;
	cin >> n >> t;
	if (t == 1) {
		cout << "Valid";
		return 0;
	}
	cout << dist[0] << "\n";
	// query
	fill(vis.begin(), vis.end(), 0);
	VIS = 1;
	int u;
	d2.resize(dist.size());
	while (n--) {
		cin >> t;
		while (t--) {
			cin >> u;
			vis[u] = VIS;
			d2[u] = dist[u];
		}
		cout << max(0, dfs2(0)) << "\n";
		++VIS;
		// return 0;
	}

	return 0;
}
