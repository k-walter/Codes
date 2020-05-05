#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("fantasydraft.in", "r", stdin);

	string name;
	int n,k,q; cin>>n>>k;
	vector<queue<string>> pref(n);
	for (auto &v : pref) {
		cin>>q;
		while (q--) {
			cin>>name;
			v.emplace(name);
		}
	}

	cin>>q; cin.get();
	unordered_set<string> del; queue<string> rank;
	while (q--) {
		cin>>name; rank.emplace(name);
	}

	vector<vector<string>> out(n);
	while (k--) {
		for (int u = 0; u < n; ++u) {
			auto &pre = pref[u];
			while (pre.size() && del.find(pre.front()) != del.end()) pre.pop();
			if (pre.size()) {
				out[u].push_back(pre.front());
				del.insert(pre.front());
				pre.pop();
				continue;
			}

			// no more preference, choose from rank
			// guaranteed to have players
			while (del.find(rank.front()) != del.end()) rank.pop();
			out[u].push_back(rank.front());
			del.insert(rank.front());
			rank.pop();
		}

	}

	for (auto &u : out) {
		for (auto &s : u) cout << s << " ";
		cout << "\n";
	}

	return 0;
}