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

bool okm[1<<16];
int V, dp[1<<16], vis[1<<16], okv[1<<16], VIS=-1;
int am[16], hi=5;

inline bool ok(int mask) {
	auto &ans = okm[mask];
	if (okv[mask] == VIS) return ans;
	okv[mask] = VIS; ans = 1;
	while (mask) {
		int u = LSOne(mask);
		mask -= u;
		for (int v,m = mask; m; m -= v) {
			v = LSOne(m);
			if (am[__builtin_ctzl(u)] & v) continue;
			return ans = 0;
		}
	}
	return 1;
}

inline int f(int mask, int depth) {
	if (mask == 0) { return 0; }
	if (depth >= hi) return hi;
	int &ans = dp[mask];
	if (vis[mask] == VIS) return ans;
	ans = hi; vis[mask] = VIS;
	for (int ss = mask; ss; ss = (ss-1) & mask) {
		if (!ok(ss)) continue;
		ans = min(ans, f(mask & ~ss, depth + 1) + 1);
	}
	// cout<<bitset<16>(mask)<<" " << ans<<"\n";
	return ans;
}

inline void solve() {
	int E; cin>>V>>E;
	if (E==0) { cout<<1<<"\n"; return; }
	// complement graph
	F0R(i,V) am[i] = (1<<V) - 1;
	while (E--) {
		int u, v; cin>>u>>v;
		am[u] &= ~(1<<v);
		am[v] &= ~(1<<u);
	}
	++VIS;
	int ans = f((1<<V)-1, 1);
	if (ans > 4) cout<<"many\n";
	else cout<<ans<<"\n";
	// find mqc < 4
	// preprocess cliques
	// for each subset, if clique, try to solve
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("mapcolouring.in", "r", stdin);

	memset(vis,-1,sizeof vis);
	memset(okv,-1,sizeof okv);
	int t; cin>>t;
	while (t--) solve();

	return 0;
}