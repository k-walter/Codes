#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("oddmanout.in", "r", stdin);

	int tc; cin>>tc;
	for (int i = 1; i <= tc; ++i) {
		int g; cin>>g;
		s.clear();
		while (g--) {
			int j; cin>>j;
			const auto &ii = s.insert(j);
			if (!ii.second) {
				s.erase(ii.first);
			}
		}
		cout << "Case #" << i << ": " << *(s.begin()) << "\n";
	}

	return 0;
}