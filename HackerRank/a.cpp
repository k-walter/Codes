
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vii dx, dy;
ll ANS = LONG_MAX;
ll sq(const ll &x) { return x * x; } 
ll dist(const ii &a, const ii &b) {
	return sq(a.first - b.first) + sq(a.second - b.second);
}
void subroutine(const vii &x, const vii &y) {
	if (x.size() == 1) return;
	const int & xm = x[x.size()>>1].first;
	vii yl, yr, xl, xr;
	for (int i = 0; i < x.size(); ++i) {
		if (y[i].second < xm) {
			yl.emplace_back(y[i]);
			xl.emplace_back(x[i]);
		}
		else {
			yr.emplace_back(y[i]);
			xr.emplace_back(x[i]);
		}
	}
	subroutine(xl, yl);
	subroutine(xr, yr);

	vector<ii> mid;
	for (auto &a : y) if (abs(a.second - xm) <= ANS) mid.emplace_back(a);
	// printf("%ld %ld : ", xm, ANS);
	// for (auto &[y,x] : mid) printf("%ld,%ld ", x,y); printf("\n");
	for (int i = 0; i < mid.size(); ++i) {
		for (int j = i+1; j < mid.size(); ++j) {
			if (mid[j].first - mid[i].first > ANS) break;
			ANS = min(ANS, dist(mid[i], mid[j]));
		}
	}
}
ll closestSquaredDistance(const vector<int> &x, const vector<int> &y) {
	for (int i = 0; i < x.size(); ++i) {
		dx.emplace_back(x[i], y[i]);
		dy.emplace_back(y[i], x[i]);
	}
	sort(dx.begin(), dx.end());
	sort(dy.begin(), dy.end());
	subroutine(dx, dy);
	// for (int i = 0; i < x.size(); ++i) {
	// 	for (int j = i+1; j < x.size(); ++j) {
	// 		ANS = min(ANS, dist(dx[i], dx[j]));
	// 		// printf("%ld %ld %ld %ld %ld\n", ANS, dx[i].first, dx[i].second, dx[j].first, dx[j].second);
	// 	}
	// }
	return ANS;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("a.in", "r", stdin);

	ll ANS = closestSquaredDistance({0,10,15}, {0,10,20});
	printf("%ld\n", ANS);

	return 0;
}