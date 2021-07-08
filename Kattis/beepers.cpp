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
#define eb emplace_back
#define fbo find_by_order
#define ook order_of_key
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORr(a, x) for (auto& a : x)
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef tuple<int,int> ii;
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

ii a[11];
int V, VIS=0, vis[11][1<<10], dp[11][1<<10];

inline int dist(int u, int v) {
	auto &[ux, uy] = a[u];
	auto &[vx, vy] = a[v];
	return abs(ux-vx) + abs(uy-vy);
}

int tsp(int u, int mask) {
	if (!mask) return dist(u, 0);
	auto &ans = dp[u][mask];
	if (vis[u][mask] == VIS) return ans;
	ans=1e9; vis[u][mask]=VIS;
	int tmp = mask;
	while (tmp) {
		int m = LSOne(tmp);
		int v = __builtin_ctz(m) + 1;
		ans = min(ans, tsp(v, mask&(~m)) + dist(u, v));
		tmp -= m;
	}
	return ans;
}

inline void solve() {
	++VIS;
	// int r,c; cin>>c>>r;
	cin>>V>>V;
	auto &[sx,sy]=a[0]; cin>>sx>>sy;
	cin>>V;
	FOR(i, 1, V+1) {
		auto &[x,y]=a[i]; cin>>x>>y;
	}
	cout<<tsp(0, (1<<V)-1)<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("beepers.in", "r", stdin);

	memset(vis, 0, sizeof vis);
	int tc; cin>>tc;
	while (tc--) solve(); 

	return 0;
}