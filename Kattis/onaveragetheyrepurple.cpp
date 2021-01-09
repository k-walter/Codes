#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("onaveragetheyrepurple.in", "r", stdin);

	// bfs --> unweighted shortest path
	int n, m; cin >> n >> m;
	vector<vector<int>> al(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	// bfs
	queue<int> q;
	vector<int> dist(n, -1);
	dist[0] = 0;
	q.push(0);
	int d = 0;
	while (q.size()) {
		int size = q.size();
		++d;
		while (size--) {
			auto &u = q.front();
			for (int &v : al[u]) {
				if (v == n-1) { cout << d - 1; return 0; }
				if (dist[v] != -1) continue;
				dist[v] = d;
				q.push(v);
			}
			q.pop();
		}
	}
	cout << 0;

	return 0;
}

/*


p --> p-1
s - x - t
|     /
x - x  
*/