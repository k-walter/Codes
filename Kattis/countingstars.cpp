#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("countingstars.in", "r", stdin);

	int no=1,m,n;
	while (cin>>m, !cin.eof()) {
		cin>>n; cin.get();
		string g[m];
		for (int i = 0; i < m; ++i) {
			getline(cin, g[i]);
			// cout << g[i] << "\n";
		}

		int cnt = 0;
		vector<ii> s;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] != '-') continue;
				++cnt;
				s.emplace_back(i,j);
				while (s.size()) {
					const auto [yy,xx] = s.back(); s.pop_back();
					for (int k = 0; k < 4; ++k) {
						const int &y = yy+dy[k], &x = xx+dx[k];
						if (y<0 || y>=m || x<0 || x>=n || g[y][x] != '-') continue;
						g[y][x] = '*'; // arbitrary
						s.emplace_back(y,x);
					}
				}
			}
		}
		cout << "Case " << no++ << ": " << cnt << "\n";
	}

	return 0;
}