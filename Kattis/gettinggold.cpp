#include <bits/stdc++.h>
using namespace std;

int w,h;
using ii = pair<int,int>;

bool valid(int y, int x) {
	return !(y >= h || y < 0 || x >= w || x < 0);
}

bool safe(int &y, int &x, vector<string>& g) {
	if (valid(y-1,x) && g[y-1][x] == 'T')
		return false;
	if (valid(y+1,x) && g[y+1][x] == 'T')
		return false;
	if (valid(y,x-1) && g[y][x-1] == 'T')
		return false;
	if (valid(y,x+1) && g[y][x+1] == 'T')
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("gettinggold.in", "r", stdin);

	cin >>w>>h;
	vector<string> g(h);
	int i = 0, x,y;
	for (auto &v : g) {
		cin >> v;
		int it = v.find('P');
		if (it != string::npos) {
			x = it; y = i;
		}
		++i;
	}
	// for (auto &v : g)
	// 	cout << v << "\n";

	vector<vector<bool>> visited(h, vector<bool>(w, false));
	visited[y][x] = true;
	deque<ii> q; q.emplace_back(y,x);
	int cnt = 0;
	while (q.size()) {
		ii yx = q.front(); q.pop_front();
		int &y = yx.first, &x = yx.second;
		char &curr = g[y][x];

		if (curr == 'G') {
			++cnt;
			// cout << "GOLD " << y << " " << x << "\n";
		}
		if (curr == '#' || !safe(y, x, g))
			continue;
		// cout << y << " " << x << "\n";

		// valid and not visited moves
		int yy = y - 1, xx = x;
		if (valid(yy,xx) && !visited[yy][xx]) {
			q.emplace_back(yy,xx);
			visited[yy][xx] = true;
		}
		yy = y + 1; xx = x;
		if (valid(yy,xx) && !visited[yy][xx]) {
			q.emplace_back(yy,xx);
			visited[yy][xx] = true;
		}
		yy = y, xx = x - 1;
		if (valid(yy,xx) && !visited[yy][xx]) {
			q.emplace_back(yy,xx);
			visited[yy][xx] = true;
		}
		yy = y, xx = x + 1;
		if (valid(yy,xx) && !visited[yy][xx]) {
			q.emplace_back(yy,xx);
			visited[yy][xx] = true;
		}

	}
	cout << cnt;

	return 0;
}