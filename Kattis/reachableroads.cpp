#include <bits/stdc++.h>
using namespace std;

void DFS(int& i, vector<vector<int>>& al, vector<bool>& status) {
	if (status[i] == false) {
		cout << i << " ";
		status[i] = true;
		for (auto &j : al[i])
			DFS(j, al, status);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("reachableroads.in", "r", stdin);

	int n; cin >> n;
	while (n--) {
		int m,r; cin >> m >> r;
		vector<vector<int>> al(m);
		while (r--) {
			int a,b; cin >> a >> b;
			al[a].push_back(b);
			al[b].push_back(a);
		}

		int cc = 0;
		vector<bool> status(m, false);
		for (int i = 0; i < m; ++i) {
			if (status[i] == false) {
				++cc;
				DFS(i, al, status);
				cout << "\n";
			}
		}
		cout << cc - 1 << "\n\n";
	}

	return 0;
}