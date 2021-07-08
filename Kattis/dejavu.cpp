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

const int MAXN = 1e5;
int xhz[MAXN], yhz[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("dejavu.in", "r", stdin);

	memset(xhz, -1, sizeof xhz);
	memset(yhz, 0, sizeof yhz);
	int n; cin>>n;
	vii a(n); for (auto &[x,y]:a) {
		cin>>x>>y; --x; --y;
		++xhz[x];
	}
	for (auto &[x,y]:a) yhz[y] += xhz[x];
	ll ans = 0;
	for (auto &[x,y]:a) {
		ans += yhz[y] - xhz[x];
	}
	cout<<ans;
	// for each point // O(n)
		// search same y // O(n)
			// if same x, continue
			// ans += no @ that x - 1

	return 0;
}