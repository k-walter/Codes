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

int b,k;

void solve() {
	cin>>b>>k; --b;
	// find largest factor of b <= k
	int ans = 1;
	for (int i = 1; i * i <= b && i <= k; ++i) {
		if (b % i) continue;
		if ((b/i) <= k) { cout<<(b/i)<<"\n"; return; }
		ans = i;
	}
	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("shortcut.in", "r", stdin);

	int t; cin>>t;
	while (t--) solve();

	return 0;
}