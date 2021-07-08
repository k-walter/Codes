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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("disastrousdoubling.in", "r", stdin);

	int n; cin>>n;
	const ll INF = 1e9+7;
	ll ans=1, hi=0;
	bool foo=0;
	F0R(i,n){
		// double curr
		ans <<= 1;
		if (ans>>61 or foo) {
			foo=1;
			ans %= INF;
		}
		// check avail
		ll u; cin>>u;
		cout<<ans<<" "<<hi<<" "<<u<<"\n";
		if (!foo and ) {cout<<"error"; return 0; }
		ans -= u;
		if (ans<0) ans += INF;
	}
	cout<<(ans % INF);

	return 0;
}