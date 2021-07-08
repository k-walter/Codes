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
const ll LLINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;

vi a, b;
vector<vi> dp;
int f(int i, int j) {
	if (i == a.size()) return 0;
	if (a.size()-i > b.size()-j) return INF;
	// if (j == b.size()) return INF;
	int &ans = dp[i][j];
	if (ans != -1) return ans;
	return ans = min(
		f(i+1, j+1) + abs(a[i]-b[j]),
		f(i, j+1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("d.in", "r", stdin);

	int n; cin>>n;
	F0R(i,n) {
		bool u; cin>>u;
		if (u) a.pb(i);
		else b.pb(i);
	}
	dp.assign(a.size(), vi(b.size(), -1));
	cout<<f(0, 0);

	return 0;
}