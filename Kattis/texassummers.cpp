#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef tuple<int,int,int> iii; // dist, x, y

long long sq(long long val) {
	return val * val;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("texassummers.in", "r", stdin);

	int n; cin>> n;
	// read in shady spots
	vector<ii> vtx;
	while (n--) {
		int x, y; cin >> x >> y;
		vtx.emplace_back(x, y);
	}
	// read in dorm, class
	ii s; auto &[sx,sy] = s;
	cin >> sx >> sy;
	ii t; auto &[tx,ty] = t;
	cin >> tx >> ty;
	vtx.emplace_back(sy, sx);
	// shortest path by sweat
	vector<ll> dist(vtx.size(), 1e18);
	vector<int> prev(vtx.size());
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(0, -1); // dist, index
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (u != -1 && dist[u] < d) continue;
		if (u == vtx.size() - 1) {
			break;
		}
		int ux, uy;
		if (u == -1) {
			ux = tx; uy = ty;
		} else {
			auto &[x, y] = vtx[u];
			ux = x; uy = y;
		}
		for (int v = 0; v < vtx.size(); ++v) {
			if (v == u) continue;
			auto &[vx, vy] = vtx[v];
			ll dd = d + sq(vx - ux) + sq(vy - uy);
			if (dd >= dist[v]) continue;
			prev[v] = u;
			dist[v] = dd;
			pq.emplace(dd, v);
		}
	}
	// if no shade, print '-'
	int cur = vtx.size() - 1;
	if (prev[cur] == -1) { cout << "-"; return 0; }
	// path from dorm to class
	while (prev[cur] != -1) {
		cur = prev[cur];
		cout << cur << "\n";
	}

	return 0;
}

/*
x___
___x

ux, uy
vx, vy

ed = ((ux - vx) ^2 + (uy - vy) ^2)^.5
d = ed^2


*/