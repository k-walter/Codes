#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n, m, VIS;
vector<vector<ii>> al; // v, hz
vector<int> vis;
vector<int> size, s2;

// -1 --> cycle
int cycle(int u) {
	if (vis[u] == 2) return size[u];
	if (vis[u] == 1) return -1; // cycle
	vis[u] = 1;
	int &dd = size[u]; dd = -1;
	for (auto &[v,hz] : al[u]) {
		int d = cycle(v);
		if (d == -1) return -1;
		if (dd == -1) dd = 1;
		d = ((ll)d * hz) % m;
		dd = (d + dd) % m;
	}
	vis[u] = 2;
	return dd;
}

// -1 --> dont update
int dfs(int u) {
	if (vis[u] == VIS) return s2[u];
	int &dd = s2[u]; dd = -1;
	vis[u] = VIS;
	for (auto &[v,hz] : al[u]) {
		int d = dfs(v);
		if (d == -1) continue;
		if (dd == -1) dd = 1;
		d = ((ll)d * hz) % m;
		dd = (d + dd) % m;
	}
	return dd;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.widgettree.in", "r", stdin);

	cin >> n >> m;
	al.resize(n);
	// read
	vector<int> hz(n);
	for (auto &vii : al) {
		int no; cin >> no;
		while (no--) {
			int v; cin >> v;
			if (hz[v] == 0) vii.emplace_back(v, 0);
			++hz[v];
		}
		for (auto &[v,h] : vii) {
			h = hz[v];
			hz[v] = 0;
		}
	}
	// find if cycle within 0
	// find subtree size
	size.resize(n);
	if (cycle(0) == -1) {
		cout << "Invalid";
		return 0;
	}
	int q, t;
	cin >> q >> t;
	if (t == 1) {
		cout << "Valid";
		return 0;
	}
	// for each query
	vis.assign(n, 0);
	VIS = 1;
	while (q--) {
		// find subtree size
		int no; cin >> no;
		while (no--) {
			int u;
			cin >> u;
			vis[u] = VIS;
			s2[u] = size[u];
		}
		cout << max(0, dfs(0)) << "\n";
	}

	return 0;
}
