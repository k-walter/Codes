#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> yx;
typedef tuple<int,ll,ll> student;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("nus.universityzoning.in", "r", stdin);

	int R,C,F,S,G;
	cin>>R>>C>>F>>S>>G;
	vector<vector<yx>> fac(F);
	for (auto &v : fac) {
		int no_pos; cin >> no_pos;
		v.resize(no_pos);
		for (auto &[y,x] : v) {
			cin >> y >> x;
		}
	}
	vector<vector<student>> fac_stu(F);
	while (S--) {
		int y, x, sid, f;
		cin >> y >> x >> sid >> f;
		--f;
		fac_stu[f].emplace_back(sid, y, x);
	}
	// find student position
	for (auto &v : fac) {			// fac positions
		sort(v.begin(), v.end());
	}
	for (auto &v : fac_stu) {		// student id per faculty
		sort(v.begin(), v.end());
		// for (auto &[sid,y,x] : v) {
		// 	cout << sid << "," << y << "," << x << " ";
		// }
		// cout << "\n";
	}
	// determine how many steps to get to position
	int f = 0;
	vector<vector<int>> dist(F);
	for (auto &v : fac_stu) {
		auto &curr_fac = fac[f];
		auto &dist_fac = dist[f];
		int i = 0;
		for (auto &[sid,sy,sx] : v) {
			auto &[fy,fx] = curr_fac[i];
			// manhatten distance
			ll dist = llabs(sy-fy) + llabs(sx-fx);
			dist_fac.push_back(dist);
			++i;
		}
		// for (int &d : dist_fac) {
		// 	cout << d << " ";
		// }
		// cout << "\n";
		++f;
	}
	// for each faculty
	vector<ll> tot_dist(F);
	f = 0;
	for (auto &dist_fac : dist) {
		// min #steps to clear compliance
		// sort students within faculty and add min amt
		sort(dist_fac.begin(), dist_fac.end());
		int t; cin >> t;
		ll &fac_tot = tot_dist[f];
		fac_tot = 0;
		for (int i = 0; i < t; ++i) {
			fac_tot += dist_fac[i];
		}
		++f;
	}
	// for (ll &d : tot_dist) {
	// 	cout << d << " ";
	// }
	// select G faculties
	sort(tot_dist.begin(), tot_dist.end());
	ll ans = 0; f = 0;
	while (G--) {
		ans += tot_dist[f];
		++f;
	}
	cout << ans;

	return 0;
}
