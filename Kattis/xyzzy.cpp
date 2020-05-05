#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("xyzzy.in", "r", stdin);

	int n,m,u,v,w,s,t;
	vector<vi> al;
	vector<int> weight;
	while (cin>>n, n!=0) {
		s = -1;
		al.assign(n, vi());
		weight.clear();
		for (u = 0; u < n; ++u) {
			cin>>w; weight.emplace_back(w);
			if (w == 0) {
				(s == -1) ? s = u : t = u;
			}
			cin>>m;
			while (m--) {
				cin>>v;
				al[u].emplace_back(v-1);
			}
		}

		cout << s << " " << t << "\n";
		for (auto &i : al) {
			for (auto &j : i)
				cout << j << " ";
			cout << "\n";
		}
		return 0;
	}
	// cannot reach = hopeless
	// cannot reach with energy = hopeless

	return 0;
}