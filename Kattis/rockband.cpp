#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("rockband.in", "r", stdin);

	int m, s; cin >> m >> s;
	vector<vi> in(m, vi(s));
	for (vi &v : in) {
		for (int &i : v) {
			cin >> i;
		}
	}
	vi hz(s, 0);
	int inv = 0;
	for (int i = 0; i < s; ++i) {
		for (vi &v : in) {
			const int &j = v[i] - 1;
			if (hz[j] == 0) ++inv;
			++hz[j];
			if (hz[j] == m) --inv;
		}
		if (inv == 0) break;
	}
	int cnt = 0;
	for (int &i : hz) if (i) ++cnt;
	cout << cnt << "\n";
	for (int i = 0; i < s; ++i)
		if (hz[i]) cout << i + 1 << " ";

	return 0;
}