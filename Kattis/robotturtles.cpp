#include <bits/stdc++.h>
using namespace std;

using iiii = tuple<int,int,int,int>;
using viiii = vector<iiii>;
using iiis = tuple<int,int,int,string>;
using vs = vector<iiis>;
using vvs = vector<vs>;
using vi = vector<int>;
using vvi = vector<vi>;

enum {UP,RIGHT,DOWN,LEFT};
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
const int dz[] = {1,3};
const int MOD = 3;
const int INF = 1e9;

vector<vvi> dist(8, vvi(8, vi(4, INF)));
vector<vvs> path(8, vvs(8, vs(4)));

void rec(int &r, int &c, int &o) {
	if (r==7 && c==0 && o==RIGHT) return;
	auto &[y,x,z,s] = path[r][c][o];
	rec(y,x,z);
	cout << s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("robotturtles.in", "r", stdin);

	char g[8][8];
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin>>g[i][j];
		}
	}

	dist[7][0][RIGHT] = 0;
	priority_queue<iiii, viiii, greater<iiii>> pq;
	pq.emplace(0,7,0,RIGHT); // dist, y, x, z

	int r,c,o; r=c=o=-1;
	while (pq.size()) {
		auto [d,yy,xx,zz] = pq.top(); pq.pop();
		if (d > dist[yy][xx][zz]) continue;
		// cout << "visiting " << yy << " " << xx << " " << zz << "\n";
		if (g[yy][xx] == 'D') { r=yy; c=xx; o=zz; break; }

		// rotate
		for (int i = 0; i < 2; ++i) {
			const int &z = (zz + dz[i]) & MOD;
			if (d+1 >= dist[yy][xx][z]) continue;
			dist[yy][xx][z] = d+1;
			path[yy][xx][z] = {yy,xx,zz,(i ? "L" : "R")};
			pq.emplace(d+1,yy,xx,z);
		}

		// fire(?) & forward
		const int &x = xx + dx[zz];
		const int &y = yy + dy[zz];
		if (y<0 || y>=8 || x<0 || x>=8 || g[y][x]=='C') continue;
		if (d+1+(g[y][x]=='I') >= dist[y][x][zz]) continue;
		dist[y][x][zz] = d+1+(g[y][x]=='I');
		path[y][x][zz] = {yy,xx,zz,(g[y][x]=='I' ? "XF" : "F")};
		pq.emplace(dist[y][x][zz],y,x,zz);
	}

	if (r == -1) { cout << "no solution"; return 0; }
	// cout << r << " " << c << " " << o << " " << dist[r][c][o] << "\n";
	rec(r,c,o);

	return 0;
}
