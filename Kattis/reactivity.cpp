#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("reactivity.in", "r", stdin);

	int n,k,u,v; cin>>n>>k;
	vector<vector<int>> al(n);
	vector<int> in(n, 0);
	while (k--) {
		cin>>u>>v;
		al[u].push_back(v);
		++in[v];
	}

	queue<int> q, out;
	for (int u = 0; u < n; ++u)	if (in[u] == 0) q.push(u);

	while (q.size() == 1) {
		auto &u = q.front();
		out.push(u);
		// cout << u << "\n";
		for (auto &v : al[u])
			if (--in[v] == 0) q.push(v);
		q.pop();
	}

	if (out.size() != n) cout << "back to the lab";
	else {
		while (out.size()) { cout << out.front() << " "; out.pop(); }
	}

	return 0;
}