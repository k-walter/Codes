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

int n,k,ans;
int own[7];
ii a[7];

void findMin() {
	// check if all owned
	int mask=(1<<k)-1;
	F0R(u, n) {
		mask &= ~(1 << own[u]);
	}
	if (mask) return;
	// assign squares
	vii w(k, {1e9, -1e9}), h(k, {1e9, -1e9});
	F0R(u, n) {
		auto &[x,y]=a[u];
		int o = own[u];
		auto &[xlo,xhi] = w[o];
		xlo=min(xlo, x);
		xhi=max(xhi, x);
		auto &[ylo,yhi] = h[o];
		ylo=min(ylo, y);
		yhi=max(yhi, y);
	}
	// find min
	int tmp=0;
	F0R(o, k) {
		auto &[xlo,xhi] = w[o];
		auto &[ylo,yhi] = h[o];
		tmp=max(tmp,xhi-xlo);
		tmp=max(tmp,yhi-ylo);
	}
	ans=min(ans,tmp);
}

void permute(int u) {
	if (u == n) { findMin(); return; }
	F0R(i, k) {
		own[u]=i;
		permute(u+1);
	}
}

inline void solve() {
	cin>>n>>k;
	F0R(i, n) { auto &[x,y]=a[i]; cin>>x>>y; }
	ans = 1e9;
	permute(0);
	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("squarefieldseasy.in", "r", stdin);

	int tc; cin>>tc;
	FOR(i, 1, tc+1) {
		cout<<"Case #"<<i<<": ";
		solve();
	}

	return 0;
}

/*
1,1
	2,2
		3,3
			6,6
				7,8
*/