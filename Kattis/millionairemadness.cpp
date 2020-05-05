#include <bits/stdc++.h>
using namespace std;

using iii = tuple<int,int,int>;
using viii = vector<iii>;
using vi = vector<int>;
const int INF = 1<<30;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("millionairemadness.in", "r", stdin);

	int h,w; cin>>h>>w;
	vector<vi> g(h, vi(w));
	for (auto &row : g)
		for (auto &i : row)
			cin >> i;

	vector<vi> dist(h, vi(w, INF)); dist[0][0] = 0;
	priority_queue<iii, viii, greater<iii>> pq; pq.emplace(0,0,0);
	while (pq.size()) {
		auto [d,yy,xx] = pq.top(); pq.pop();
		if (d > dist[yy][xx]) continue;
		if (yy==(h-1) && xx==(w-1)) break;
		
		const int &cc = g[yy][xx];
		for (int i = 0; i < 4; ++i) {
			const int &y=yy+dy[i], &x=xx+dx[i];
			if (y<0 || y>=h || x<0 || x>=w) continue;
			
			// const int& gives weird behaviour
			if (max(g[y][x]-cc, d) >= dist[y][x]) continue;
			dist[y][x] = max(g[y][x]-cc, d);
			pq.emplace(dist[y][x], y, x);
		}
	}

	// for (auto &r : dist) {
	// 	for (auto &i : r)
	// 		cout << i << " ";
	// 	cout << "\n"; 273501091
	// }

	cout << dist[h-1][w-1];

	return 0;
}