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

inline void solve() {
	int l,m; cin>>l>>m; l*=100;
	queue<int> q[2]; bool lef=1;
	while (m--) {
		int t; string s; cin>>t>>s;
		if (s[0]=='l') q[1].emplace(t);
		else q[0].emplace(t);
	}
	int ans=0;
	while (q[0].size() or q[1].size()) {
		for (int len=l; q[lef].size() and q[lef].front()<=len;) {
			len-=q[lef].front(); q[lef].pop();
		}
		++ans; lef=!lef;
	}
	cout<<ans<<"\n";
		// if nobody waiting, change time
		// enqueue while <= ti
		// ship over
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("ferryloading4.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) solve();

	return 0;
}