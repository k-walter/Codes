#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using vi = vector<int>;
using viii = vector<iii>;
const int INF = 1e9;

int dy[] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {-1,1,-2,2,-2,2,-1,1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("hidingplaces.in", "r", stdin);

	int n; cin>>n; cin.get();
	while (n--) {
		string line; getline(cin, line);
		int c = line[0] - 'a', r = line[1] - '1';

		vector<vi> dist(8, vi(8, INF)); dist[r][c] = 0;
		viii s; s.emplace_back(0,r,c);
		while (s.size()) {
			auto [d,yy,xx] = s.back(); s.pop_back();
			if (d++ > dist[yy][xx]) continue;
			for (int i = 0; i < 8; ++i) {
				const int &y = yy+dy[i], &x = xx+dx[i];
				if (y<0 || y>=8 || x<0 || x>=8 || d>dist[y][x]) continue;
				dist[y][x] = d;
				s.emplace_back(d,y,x);
			}
		}

		// for (auto &v : dist) {
		// 	for (auto &i : v)
		// 		cout << i << " ";
		// 	cout << "\n";
		// }

		int maxx = 0;
		vector<ii> no;
		for (int y = 7; y >= 0; --y) {
			for (int x = 0; x < 8; ++x) {
				if (dist[y][x] < maxx) continue;
				else if (dist[y][x] > maxx) { no.clear(); maxx = dist[y][x]; }
				no.emplace_back(x,y);
			}
		}
		cout << maxx;
		for (auto &[x,y] : no)
			cout << " " << (char)('a'+x) << (char)('0'+(y+1));
		cout << "\n";

		// Sort 8-1, a-h
	}

	return 0;
}