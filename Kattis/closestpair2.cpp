#include <bits/stdc++.h>
using namespace std;
const double INF = DBL_MAX;

struct Pt { double x, y; };
typedef tuple<Pt,Pt,double> pts;
Pt Px[100000], Py[100000], Ps[100000];

inline double sq(const double &a) { return a * a; }
inline double dist(const Pt &a, const Pt &b) { return sq(a.x-b.x) + sq(a.y-b.y); }
Pt u, v; double d;
inline pts solve(Pt Px[], Pt Py[], const int &n) {
	if (n == 1) return {Px[0], Py[0], INF};

	// Split Py into <=x and >=x
	int mid = n >> 1, l = 0, r = 0, cnt = mid;
	Pt Pyl[mid], Pyr[n-mid];
	for (int i = 0; i < n && Px[i].x < Px[mid].x; ++i) --cnt; // #pts = x_mid on left
	for (int i = 0; i < n; ++i) { // O(n)
		if (Py[i].x < Px[mid].x) Pyl[l++] = Py[i];
		else if (Py[i].x == Px[mid].x && cnt) { --cnt; Pyl[l++] = Py[i]; }
		else Pyr[r++] = Py[i];
	}

	// Conquer
	const auto &[ul,vl,dl] = solve(Px, Pyl, mid);
	const auto &[ur,vr,dr] = solve(Px+mid, Pyr, n-mid);
	if (dl < dr) { d = dl; u = ul; v = vl; }
	else { d = dr; u = ur; v = vr; }

	// Merge
	l = 0;
	for (int i = 0; i < n; ++i)
		if (abs(Py[i].x - Px[mid].x) < d) // Limit to strip
			Ps[l++] = Py[i];
	for (int i = 0; i < l; ++i) {
		for (int j = i+1; j < l && (Ps[j].y - Ps[i].y) < d; ++j) { // Search upwards
			if (dist(Ps[i], Ps[j]) >= d) continue;
			d = dist(Ps[i], Ps[j]);
			u = Ps[i]; v = Ps[j];
		}
	}

	return {u,v,d};
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("closestpair2.in", "r", stdin);

	int n;
	while (scanf("%d",&n), n) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf",&Py[i].x,&Py[i].y);
			Px[i].x = Py[i].x; // = 100 * a;
			Px[i].y = Py[i].y; // = 100 * b;
		}
		sort(Px, Px+n, [](const Pt &a, const Pt &b) {
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		});
		sort(Py, Py+n, [](const Pt &a, const Pt &b) {
			if (a.y == b.y) return a.x < b.x;
			return a.y < b.y;
		});
		const auto &[u,v,_] = solve(Px, Py, n);
		printf("%.2f %.2f %.2f %.2f\n", u.x, u.y, v.x, v.y);
	}

	return 0;
}