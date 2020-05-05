#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using viii = vector<iii>;
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};
const int REM = 0;

int h,w;
int g[20][60];
ii path[20][60];
int dist[20][60];

void print() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (g[i][j] == REM) cout << " ";
			else cout << g[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("blockcrusher.in", "r", stdin);

	string line;
	while (cin>>h>>w, !(h==0 && w==0)) {
		cin.get();
		for (int i = 0; i < h; ++i) {
			getline(cin, line);
			for (int j = 0; j < w; ++j) g[i][j] = line[j] - '0';
		}

		if (h==1) {
			*min_element(g[0], g[0]+w) = REM;
			print(); continue;
		}

		viii tmp;
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < w; ++i) {
			tmp.emplace_back(g[0][i], 0, i);
			dist[0][i] = g[0][i];
		}

		int r=h-1,c;
		priority_queue<iii, viii, greater<iii>> pq(tmp.begin(), tmp.end());
		while (pq.size()) {
			auto [d,yy,xx] = pq.top(); pq.pop();
			if (d > dist[yy][xx]) continue;
			// cout << d << " " << yy << " " << xx << "\n";// continue;
			if (yy == r) { c=xx; break; }
			for (int i = 0; i < 8; ++i) {
				const int &y=yy+dy[i], &x=xx+dx[i];
				if (y<0 || y>=h || x<0 || x>=w) continue;
				if (dist[y][x]!=-1 && d+g[y][x]>=dist[y][x]) continue;
				dist[y][x] = d+g[y][x];
				path[y][x] = {yy,xx};
				pq.emplace(dist[y][x], y, x);
			}
		}

		while (g[r][c]=REM, r != 0) tie(r,c) = path[r][c];
		print();
	}

	return 0;
}