#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

int w,h;
int g[500][500];
bool vis[500][500] = {false};
queue<ii> q;

int flood(int &r, int &c) {
	vis[r][c] = true;
	q.emplace(r,c);

	bool ac = true;
	int no = 1;
	while (q.size()) {
		auto &[yy,xx] = q.front();

		// cout << "visiting " << yy << " " << xx << "\n";
		for (int i = 0; i < 4; ++i) {
			const int &y=yy+dy[i], &x=xx+dx[i];
			if (y<0 || y>=h || x<0 || x>=w || g[y][x]>g[yy][xx]) continue;
			if (g[y][x] < g[r][c]) { ac = false; continue; }
			if (vis[y][x]) continue;
			vis[y][x] = true;
			++no;
			q.emplace(y,x);
		}
		q.pop();
	}

	// cout << (ac ? no : 0) << "\n";
	return ac ? no : 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("terraces.in", "r", stdin);

	cin>>w>>h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			cin>>g[i][j];
		}

	int no = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			if (vis[i][j]) continue;
			no += flood(i,j);
		}

	cout << no;

	return 0;
}