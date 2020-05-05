#include <bits/stdc++.h>
using namespace std;

const long long INF = 1<<30;
using vi = vector<int>;
using ii = pair<int,int>;

int s,t,k,v;
vector<vector<ii>> al; // vtx, weight
unordered_map<int, vector<vi>> g; // [source], k, t

void bf() {
	// Get sauce
	auto &gg = g[s];

	// Initialise if empty
	if (gg.empty()) {
		gg.emplace_back(vi(v, INF));
		gg[0][s] = 0;
		for (const ii &i : al[s])
			gg[0][i.first] = i.second;

		// cout << gg.size() << " | ";
		// for (auto &i : gg.back())
		// 	cout << i << " ";
		// cout << "\n";
	}

	// DP
	while (gg.size() < k) { // up to k edges
		gg.emplace_back(gg.back());
		const vi &prev = gg[gg.size()-2];
		vi &curr = gg.back();

		// Bellman Ford
		for (int i = 0; i < v; ++i) { // for each vtx
			if (prev[i] == INF || i == s) continue; // exit if not reached
			// cout << i << " : ";
			for (const ii &j : al[i]) { // for each edge
				// cout << j.first << " " << j.second << ", ";
				// min(curr dist + edge, old dist)
				curr[j.first] = min(prev[i] + j.second, curr[j.first]);
			}
			// cout << "\n";
		}

		// cout << gg.size() << " | ";
		// for (auto &i : gg.back())
		// 	cout << i << " ";
		// cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("shortestpath4.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) {
		cin.get();
		cin>>v; // vertex
		al.clear(); al.resize(v);
		for (auto &i : al) {
			int x; cin>>x; // edges
			while (x--) {
				int a,b; cin>>a>>b; // vtx, weight
				i.emplace_back(a,b);
			}
		}

		g.clear();
		int q; cin>>q; // query
		while (q--) {
			cin>>s>>t>>k; --k;
			if (k == 0) { // no jumps!
				cout << -1 << "\n";
				continue;
			}

			bf();
			int out = g[s][k-1][t];
			if (out == INF) out = -1;
			cout << out << "\n";
		}
		cout << "\n";
	}

	return 0;
}