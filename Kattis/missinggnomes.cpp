#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("missinggnomes.in", "r", stdin);

	int n, m; cin >> n >> m;
	vector<bool> vis(n+1, 0);
	vector<int> lef(m);
	for (int &i : lef) {
		cin >> i;
		vis[i] = 1;
	}
	auto it = lef.begin();
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		while (it != lef.end() && *it < i) {
			cout << *it << "\n";
			++it;
		}
		cout << i << "\n";
	}
	while (it != lef.end()) {
		cout << *it << "\n";
		++it;
	}

	return 0;
}


/*

6 4 2 1
3 5 7

3 5 6 4 2 1 7
*/