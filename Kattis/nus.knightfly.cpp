#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> ii;
enum dir { UP=0, DOWN, LEFT, RIGHT };
typedef array<int,4> udlr;
vector<vector<dir>> knightfly {
	{UP, UP, LEFT},
	{UP, UP, RIGHT},
	{RIGHT, RIGHT, UP},
	{RIGHT, RIGHT, DOWN},
	{DOWN, DOWN, RIGHT},
	{DOWN, DOWN, LEFT},
	{LEFT, LEFT, DOWN},
	{LEFT, LEFT, UP},
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.knightfly.in", "r", stdin);

	// save clear in um, coord
	int n,sx,sy,tx,ty; cin>>n>>sx>>sy>>tx>>ty;
	if (sx==tx && sy==ty) {
		cout << 0;
		return 0;
	}
	
	vector<ii> clr(n);
	int i = 1, s, t;
	for (auto &[x,y,u]:clr) {
		cin>>x>>y; 
		if (sx==x && sy==y) s = i;
		else if (tx==x && ty==y) t = i;
		u = i++;
	}
	// sort by row (coord), ie l->r, d->u
	vector<udlr> al(n+1);
	sort(clr.begin(), clr.end());
	for (int i = 1; i < n; ++i) {
		const auto &[ux,uy,u] = clr[i];
		const auto &[vx,vy,v] = clr[i-1];
		const bool &sameCol = ux == vx;
		if (!sameCol) continue;
		al[v][UP] = u;
		al[u][DOWN] = v;
	}
	// sort by col (coord), ie d->u, l->r
	sort(clr.begin(), clr.end(), [](const ii &a, const ii &b) {
		const auto &[ux,uy,u] = a;
		const auto &[vx,vy,v] = b;
		if (uy == vy) return ux < vx;
		return uy < vy;
	});
	for (int i = 1; i < n; ++i) {
		const auto &[ux,uy,u] = clr[i];
		const auto &[vx,vy,v] = clr[i-1];
		const bool &sameRow = uy == vy;
		if (!sameRow) continue;
		al[v][RIGHT] = u;
		al[u][LEFT] = v;
	}
	// bfs (c)
	queue<int> q; q.push(s);
	vector<bool> vis(n+1,0); vis[s] = 1;
	int ans = 1, size; int v;
	while (size = q.size()) {
		while (size--) {
			auto &u = q.front();
			for (auto &fly : knightfly) {
				v = u;
				for (auto &step : fly) {
					v = al[v][step];
					if (v == 0) break;
				}
				if (v == t) {
					cout << ans;
					return 0;
				}
				if (vis[v]) continue;
				vis[v]=1; q.push(v);
			}
			q.pop();
		}
		++ans;
	}
	cout << -1;

	return 0;
}