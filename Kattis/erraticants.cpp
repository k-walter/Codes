#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> yx;

int al[200][200];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1}; // up 0, down 1, left 2, right 3

inline void bfs(int ty, int tx) {
	if (ty == 100 && tx == 100) {
		cout << "0\n";
		return;
	}

	int ans = 0, n;
	al[ty][tx] |= (1 << 4);
	queue<yx> q; q.emplace(ty, tx);
	while (q.size()) {
		n = q.size();
		// cout << "dist " << ans << "\n";
		++ans;
		while (n--) {
			auto &[yy,xx] = q.front();
			// cout << "at " << yy << " " << xx << "\n";
			auto &dir = al[yy][xx];
			for (int i = 0; i < 4; ++i) {
				if (!(dir & (1 << i))) continue;
				const int &y = yy+dy[i], &x = xx+dx[i];
				if (y==100 && x==100) {
					cout << ans << "\n";
					return;
				}
				if (al[y][x] & (1 << 4)) continue;
				al[y][x] |= (1 << 4);
				q.emplace(y, x);
			}
			q.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("erraticants.in", "r", stdin);

	int tc, n, dir; cin >> tc;
	char c;
	int y, x, yy, xx;
	while (tc--) {
		cin >> n;
		memset(al, 0, sizeof al);
		y = x = 100;
		while (n--) {
			cin >> c;
			yy = y; xx = x;
			switch (c) {
				case 'N': dir=0; --y; break;
				case 'S': dir=1; ++y; break;
				case 'W': dir=2; --x; break;
				case 'E': dir=3; ++x; break;
			}
			al[yy][xx] |= (1 << dir);
			al[y][x] |= (1 << (dir ^ 1));
			yy = y; xx = x;
		}
		bfs(y, x);
	}

	return 0;
}
