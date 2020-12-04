#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.universityzoning.in", "r", stdin);

	int R,C,F,S,G; 
	cin>>R>>C>>F>>S>>G;
	vector<vii> fac(F);
	// read faculties
	int f;
	for (vii &v : fac) {
		cin>>f;
		v.resize(f);
		for (auto &[y,x]:v){
			cin>>y>>x;
			--y; --x;
		}
		sort(v.begin(), v.end());
	}
	// for (vii &v : fac) {for (auto &[y,x]:v) printf("%d,%d ",y,x); printf("\n"); }
	// read students
	vector<viii> facs(F); // sid, y, x
	int y,x,d;
	while (S--) {
		cin>>y>>x>>d>>f;
		facs[f-1].emplace_back(d-1,y-1,x-1);
	}
	// read compliance
	vector<int> T(F);
	for (int &t : T) {
		cin>>t;
		if (t == 0) --G;
	}
	vector<pair<ll, int>> dist; // dist, fac
	// calculate dist for each student
	for (int i = 0; i < F; ++i) {
		auto &v = facs[i];
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); ++j) {
			auto &[_,sy,sx] = v[j];
			auto &[fy,fx] = fac[i][j];
			const ll &d = llabs((ll)sy - fy) + llabs((ll)sx - fx);
			// printf("fac %d student %d,%d pos %d,%d dis %lld\n", i, sy,sx, fy,fx, d);
			dist.emplace_back(d, i);
		}
	}
	sort(dist.begin(), dist.end());
	// min for each faculty
	vector<ll> fdist(F, 0);
	for (auto &[d,f]: dist) {
		if (T[f] <= 0) continue;
		--T[f]; fdist[f] += d;
	}
	// min #fac
	ll ans = 0;
	sort(fdist.begin(), fdist.end());
	// for (ll &d : fdist) cout << d << " " ; cout << "\n";
	for (ll &d : fdist) {
		if (G <= 0) break;
		ans += d; --G;
	}
	cout << ans;

	return 0;
}