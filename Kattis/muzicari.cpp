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

const int T=5000,N=500;
int t,n,dp[N][T],arr[N];
bool nex[N][T];
bitset<N> up;

int f(int i, int st) {
	if (st >= t) return st==t ? st : 0;
	if (i >= n) return st;
	int &ans = dp[i][st];
	if (ans != -1) return ans;
	ans = f(i+1, st);
	st += arr[i];
	if (f(i+1,st)>ans) {
		nex[i][st-arr[i]]=1; ans=f(i+1,st);
	}
	return ans;
}

void dfs(int i, int st) {
	if (i>=n or st>=t) return;
	if (nex[i][st]) { up[i]=1; dfs(i+1, st+arr[i]); }
	else dfs(i+1, st);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("muzicari.in", "r", stdin);

	memset(dp,-1,sizeof dp);
	cin>>t>>n;
	F0R(i,n) cin>>arr[i];
	f(0,0); dfs(0,0);
	int L=0,R=0;
	F0R(i,n) {
		if (up[i]) { cout<<L; L+=arr[i]; }
		else { cout<<R; R+=arr[i]; }
		cout<<" ";
	}

	return 0;
}