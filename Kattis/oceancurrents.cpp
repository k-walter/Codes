#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int,int,int> ii;
int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

vector<vi> g, vis, dist;
int n, m;
int q, ty, tx; 

inline bool ok(int d, int y, int x, int i) {
	if (y<0 || y>=n || x<0 || x>=m) return 0;
	if (vis[y][x]==i && d>=dist[y][x]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("oceancurrents.in", "r", stdin);

	cin >> n >> m;
	g.assign(n, vi(m));
	dist.assign(n, vi(m));
	vis.assign(n, vi(m, 0));
	char c;
	for (vi &v : g)
		for (int &i : v) {
			cin >> c;
			i = c - '0';
		}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		deque<ii> q;
		cin >> ty >> tx; --ty; --tx;
		q.emplace_back(0, ty, tx);
		vis[ty][tx] = i;
		dist[ty][tx] = 0;
		cin >> ty >> tx; --ty; --tx;
		if (vis[ty][tx] == i) { cout << 0 << "\n"; continue; }
		while (q.size()) {
			auto [dd, yy, xx] = q.front();
			// cout << "dist " << d << " at " << yy << " " << xx << "\n";
			q.pop_front();
			for (int j = 0; j < 8; ++j) {
				int d = dd+(g[yy][xx]!=j), y = yy+dy[j], x = xx+dx[j];
				if (y==ty && x == tx) { cout << d << "\n"; goto END; }
				if (!ok(d, y, x, i)) continue;
				// cout << "add " << y << " " << x << " dir " << g[y][x] << "\n";
				vis[y][x] = i;
				dist[y][x] = d;
				
				if (q.size() && d <= get<0>(q.front())) q.emplace_front(d, y, x);
				else q.emplace_back(d, y, x);
			}
		}
		END:;
	}


	return 0;
}