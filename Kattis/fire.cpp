#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using bii = tuple<bool,int,int>;
using vi = vector<int>;
const int INF = 1e9;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("fire.in", "r", stdin);

	int r,c; cin>>r>>c; cin.get();

	char g[r][c];
	vector<vi> dist(r, vi(c, 1e9));
	queue<bii> q;
	int px,py;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> g[i][j];
			switch (g[i][j]) {
				case 'J':
					px = j; py = i;
					dist[i][j] = 0;
					break;
				case 'F':
					dist[i][j] = 0;
					q.emplace(false,i,j);
					break;
			}
		}
	}

	--r; --c;
	if (py==0 || py==r || px==0 || px==c) { cout<<1; return 0; }

	// Floodfill fire & Joe
	int cnt = 1; q.emplace(true,py,px); // any more joe?
	while (cnt && q.size()) {
		auto &[isJ,yy,xx] = q.front();
		const int &d = dist[yy][xx] + 1;
		for (int i = 0; i < 4; ++i) {
			const int &y = yy+dy[i], &x = xx+dx[i];
			if (y<0 || y>r || x<0 || x>c || g[y][x]=='#' || d>=dist[y][x]) continue;
			if (isJ) {
				if (y==0 || y==r || x==0 || x==c) {
					cout << d+1;
					return 0;
				}
				++cnt;
			}
			dist[y][x] = d;
			q.emplace(isJ,y,x);
		}
		q.pop();
		if (isJ) --cnt;
	}

	// for (auto &v : dist) {
	// 	for (auto &i : v)
	// 		cout << i << "\t";
	// 	cout << "\n";
	// }

	cout << "IMPOSSIBLE";

	// for (auto &v : dist) {
	// 	for (auto &i : v)
	// 		cout << i << " ";
	// 	cout << "\n";
	// }

	// for (auto &s : g)
	// 	cout << s << "\n";

	return 0;
}