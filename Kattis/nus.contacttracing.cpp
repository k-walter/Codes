#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int,bool,int> ibi; // time, start/stop, vtx

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.contacttracing.in", "r", stdin);

	int n,d,c; cin>>n>>d>>c;
	// add infected
	vector<bool> vis(n, 0);
	queue<int> q;
	while (c--) {
		int t; cin >> t; --t;
		q.push(t);
		vis[t] = 1;
	}
	// add timings
	vector<ibi> a;
	int s,t;
	for (int i = 0; i < n; ++i) {
		cin>>s>>t;
		a.emplace_back(s, 0, i);
		a.emplace_back(t, 1, i);
	}
	// create al
	sort(a.begin(), a.end());
	unordered_set<int> us;
	vector<vector<int>> al(n);
	for (auto &[t,ok,u] : a) {
		if (ok) { us.erase(u); continue; }
		for (auto &v : us) {
			al[u].push_back(v);
			al[v].push_back(u);
		}
		us.insert(u);
	}
	// bfs
	int size;
	while (d-- && (size = q.size())) {
		while (size--) {
			int &u = q.front();
			for (int &v : al[u]) {
				if (vis[v]) continue;
				vis[v] = 1;
				q.push(v);
			}
			q.pop();
		}
	}
	// ans
	for (int u = 0; u < n; ++u) {
		if (!vis[u]) continue;
		cout << u+1 << " ";
	}

	return 0;
}