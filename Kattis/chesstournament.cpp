#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<vi> al, eq;
vector<int> vis; // unvis, vis, exp

bool dfs(int &i) {
	if (vis[i] == 1) return true;
	if (vis[i] == 2) return false;
	vis[i] = 1;
	// cout << "visiting " << i << " and ";

	// visit all equal
	queue<int> q,q2;
	for (auto &j : eq[i]) { q.push(j); vis[j] = 1; }
	for (auto &j : al[i]) q2.push(j);
	while (q.size()) {
		auto &j = q.front();
		// cout << j << " ";
		for (auto &k : al[j]) q2.push(k);
		for (auto &k : eq[j]) {
			if (vis[k] != 0) continue;
			vis[k] = 1;
			q.push(k);
		}
		q.pop();
	}
	// cout << "\n";

	while (q2.size()) {
		if (dfs(q2.front())) return true;
		q2.pop();
	}

	vis[i] = 2;
	for (auto &j : eq[i]) { q.push(j); vis[j] = 2; }
	while (q.size()) {
		auto &j = q.front();
		for (auto &k : eq[j]) {
			if (vis[k] != 1) continue;
			vis[k] = 2;
			q.push(k);
		}
		q.pop();
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("chesstournament.in", "r", stdin);

	int n,m; cin>>n>>m;
	al.resize(n); eq.resize(n); vis.assign(n,0);

	int u,v; char op;
	while (m--) {
		cin>>u>>op>>v;
		switch (op) {
			case '=': eq[u].push_back(v); eq[v].push_back(u); break;
			case '>': al[u].push_back(v); break;
		}
	}

	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0) {
			if (dfs(i)) {
				cout << "inconsistent"; return 0;
			}
		}
	}
	cout << "consistent";


	return 0;
}