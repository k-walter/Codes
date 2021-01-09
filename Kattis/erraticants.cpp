#include <bits/stdc++.h>
using namespace std;
typedef tuple<bool,bool,bool,bool> udlr;
typedef vector<udlr> vi;
typedef pair<int,int> yx;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("erraticants.in", "r", stdin);

	int n; cin >> n;
	while (n--) {
		int m; cin >> m;
		vector<vi> g(200, vb(200));
		// y * x --> u/d/l/r , (y,x), (y,x)
		int y = 100, x = 100;
		while (m--) {
			char c; cin >> c;
			auto &[u,d,l,r] = g[y][x];
			switch (c) {
				case 'S': d=1; ++y; break;
				case 'N': u=1; --y; break;
				case 'E': r=1; ++x; break;
				case 'W': l=1; --x; break;
			}
		}
		int ty = y, tx = x;
		queue<yx> q; q.push(100, 100);
		vector<vector<bool>> vis(200, vector<bool>(200, 0));
		vis[100][100] = 1;
		int d = 0;
		while (q.size()) {
			int size = q.size();
			while (size--) {
				auto &[yy, xx] = q.front();

				for (int i = 0; i < 4; ++i) {
					get<i>(q.front())
				}
				q.pop();
			}
		}
	}

	return 0;
}

/*

s   x x
x x x x
    t
*/