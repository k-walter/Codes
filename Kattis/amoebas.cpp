#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("amoebas.in", "r", stdin);

	int n, m; cin >> n >> m;
	char g[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}
	int ans = 0, yy, xx, x, y;
	int dy[] = {-1,-1,-1,0,0,1,1,1};
	int dx[] = {-1,0,1,-1,1,-1,0,1};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] != '#') continue;
			yy = i; xx = j; ++ans;
			while (g[yy][xx] == '#') {
				g[yy][xx] = 0;
				for (int k = 0; k < 8; ++k) {
					y = yy + dy[k]; x = xx + dx[k];
					if (y<0 || y>=n || x<0 || x>=m) continue;
					if (g[y][x] != '#') continue;
					yy=y; xx=x; break;
				}
			}
		}
	}
	cout << ans;

	return 0;
}