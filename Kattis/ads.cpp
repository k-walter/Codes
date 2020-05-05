#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;

const char *allow_c = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm,.?! +";
const unordered_set<char> allow(allow_c,allow_c+strlen(allow_c)); // initialise set with char
const char DEL = '\x00';

int h,w;
char g[200][200];
bool visit[200][200] = {false};
const int dy[] = {-1,0,1,0}; // u,l,d,r
const int dx[] = {0,-1,0,1};

void ff(const int &y_origin, const int &x_origin) {
	// Find border with dfs
	int t,b,l,r; t=b=y_origin, l=r=x_origin; // set starting pt as minmax!
	vector<ii> s; s.emplace_back(y_origin,x_origin); // stack for dfs means no extra fn
	visit[y_origin][x_origin] = true; // stack for dfs requires setting before recursing
	while (s.size()) {
		const auto [y,x] = s.back(); s.pop_back();
		for (int i = 0; i < 4; ++i) {
			const int &yy = y+dy[i], &xx = x+dx[i];
			if (yy<0 || yy>=h || xx<0 || xx>=w) continue; // de morgan's means OR rather than AND
			if (visit[yy][xx] || g[yy][xx]=='+') continue; // if deleted, definitely visited
			
			visit[yy][xx] = true; // stack for dfs requires setting before recursing
			if (t >= yy && l >= xx) { t = yy; l = xx; } // top and left at the same time!
			if (b <= yy && r <= xx) { b = yy; r = xx; }
			s.emplace_back(yy,xx);
		}
	}

	// Check if valid border
	--t; --l; ++b; ++r; // stop before bounds is faster!
	if (t<0 || l<0 || b>=h || r>=w) return; // border cannot be outside of img

	// Delete w floodfill (prevents re-delete)
	s.emplace_back(b,r); // starting from bottom right
	g[b][r] = DEL;
	while (s.size()) {
		const auto [y,x] = s.back(); s.pop_back();
		for (int i = 0; i < 2; ++i) { // move up and left
			const int &yy = y+dy[i], &xx = x+dx[i];
			if (yy < t || xx < l || g[yy][xx] == DEL) continue; // stop at top left
			g[yy][xx] = DEL;
			s.emplace_back(yy,xx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("ads.in", "r", stdin);

	cin>>h>>w; cin.get();
	vector<ii> v;
	for (int i = 0; i < h; ++i) {
		string line; getline(cin, line); // cin cannot read ' '
		for (int j = 0; j < w; ++j) {
			g[i][j] = line[j];
			if (allow.find(g[i][j]) == allow.end()) // illegal char
				v.emplace_back(i,j);
		}
	}

	for (const auto &[i,j] : v) if (!visit[i][j]) ff(i, j); // not removed

	for (int i = 0; i < h-1; ++i) {
		for (int j = 0; j < w; ++j)
			cout << (g[i][j] == DEL ? ' ' : g[i][j]);
		cout << "\n";
	}
	for (int i = 0; i < w; ++i) cout << (g[h-1][i] == DEL ? ' ' : g[h-1][i]);

	return 0;
}