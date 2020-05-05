#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("kattisquest.in", "r", stdin);

	int n; cin >> n; cin.get();
	map<int, priority_queue<int>> m;
	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int e,g; cin >> e >> g; cin.get();
			m[e].push(g);
		}

		else {
			int e; cin >> e; cin.get();
			long long tot = 0;

			while (e > 0) {
				auto it = m.upper_bound(e);
				if (it == m.begin())
					break;
				--it; // upper bound returns 1 after

				e -= it->first;
				tot += it->second.top(); it->second.pop();
				if (it->second.empty())
					m.erase(it);
			}
			cout << tot << "\n";
		}
	}

	return 0;
}