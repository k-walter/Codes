#include <bits/stdc++.h>
using namespace std;

int r,c, den=2, bin=-1, cur;
vector<vector<int>> g;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool valid(const int &y, const int &x) {
	return y>=0 && y<r && x>=0 && x<c && g[y][x] == cur;
}

void dfs(const int &y, const int &x, const int &grp) {
	vector<pair<int,int>> s; s.emplace_back(y,x);
	g[y][x] = grp;

	while (s.size()) {
		auto ii = s.back();
		s.pop_back();

		for (int i = 0; i < 4; ++i) {
			const int &yy = ii.first+dy[i], &xx = ii.second+dx[i];
			if (valid(yy, xx)) {
				g[yy][xx] = grp;
				s.emplace_back(yy, xx);
			}
		}
	}
}

void visit(const int &y, const int &x) {
	switch (g[y][x]) {
		case 1:
			cur = 1;
			dfs(y, x, den++);
			break;
		case 0:
			cur = 0;
			dfs(y, x, bin--);
			break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("10kindsofpeople.in", "r", stdin);

	cin>>r>>c;
	g.resize(r,vector<int>(c));
	for (auto &row : g) {
		string line; cin>>line;
		for (int i = 0; i < c; ++i)
			row[i] = line[i]-'0';
	}

	int q; cin>>q;
	while (q--) {
		int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
		--r1; --c1; --r2; --c2;
		visit(r1,c1); // visit(r2,c2); // only need to visit 1 if same CC
		if (g[r1][c1] == g[r2][c2])
			cout << (g[r1][c1] > 0 ? "decimal" : "binary");
		else
			cout << "neither";
		cout << "\n";
	}

	return 0;
}