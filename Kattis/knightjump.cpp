#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;

string g[100];
vector<vector<int>> dist;
int dy[] = {2,2,-2,-2,1,1,-1,-1};
int dx[] = {1,-1,1,-1,2,-2,2,-2};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("knightjump.in", "r", stdin);

	int n; cin>>n; cin.get();
	int r,c;
	for (int i = 0; i < n; ++i) {
		getline(cin,g[i]);
		for (int j = 0; j < n; ++j) {
			if (g[i][j] == 'K') {
				r = i; c = j;
			}
		}
	}
	if (r == 0 && c == 0) { cout << 0; return 0; }

	dist.assign(n, vector<int>(n, 1e9)); dist[r][c] = 0;
	queue<ii> q; q.emplace(r,c);
	while (q.size()) {
		const auto [yy,xx] = q.front(); q.pop();
		const int &d = dist[yy][xx] + 1;
		// cout << "visited " << yy << " " << xx << " " << d << "\n";
		for (int i = 0; i < 8; ++i) {
			const int &y = dy[i]+yy, &x = dx[i]+xx;
			if (y<0 || y>=n || x<0 || x>=n || g[y][x]=='#' || d>=dist[y][x]) continue;
			if (y == 0 && x == 0) { cout << d; return 0; }
			dist[y][x] = d;
			q.emplace(y,x);
		}
	}
	cout << -1;

	return 0;
}