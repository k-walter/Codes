#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORr(a, x) for (auto& a : x)
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef tuple<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef tuple<int,ll,ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vdit;
const ll INF = 1e18;

inline int sq(int a) { return a*a; }
inline int dist(const ii&a, const ii&b) {
	return sq(a.first-b.first) + sq(a.second-b.second);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("retribution.in", "r", stdin);

	int n,m,p; cin>>n>>m>>p;
	cout<<fixed<<setprecision(9);
	vii j(n),t(m),f(p);
	for (auto &[x,y]:j) cin>>x>>y;
	for (auto &[x,y]:t) cin>>x>>y;
	for (auto &[x,y]:f) cin>>x>>y;

	vector<iii> a;
	F0R(i,n) F0R(h,m)
		a.emplace_back(dist(j[i],t[h]), i, h);
	sort(a.begin(), a.end());
	double ans=0;
	bitset<1000> tvis=0, fvis=0;
	vi vis(n,0);
	for (auto &[d,u,v]:a) {
		if (tvis[v]) continue;
		if (vis[u]==1) continue;
		tvis[v]=vis[u]=1;
		ans += pow(d, 0.5);
	}

	a.clear();
	F0R(i,n) F0R(h,p)
		a.emplace_back(dist(j[i],f[h]), i, h);
	sort(a.begin(), a.end());
	for (auto &[d,u,v]:a) {
		if (fvis[v]) continue;
		if (vis[u]==2) continue;
		fvis[v]=1; vis[u]=2;
		ans += pow(d, 0.5);
	}
	cout<<ans;

	return 0;
}

/*
1,0 2,0
0,0 3,0
1,1 2,1
*/