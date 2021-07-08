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

int n,m;
vector<vi> dp;
int a[501], s[501], ans;

int f(int u, int port) {
	if (port>n or (s[u]-port)>n) return u-1;
	if (u == m) return u;
	// cout<<u<<" port "<<port<<" starboard "<<s[u]-port<<"\n";
	int &ans = dp[u][port];
	if (ans != -1) return ans;
	ans = max(f(u+1,port+a[u]), f(u+1,port));
	// cout<<u<<" port "<<port<<" ans "<<ans<<"\n";
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("ferryloading.in", "r", stdin);

	cin>>n; n*=100;
	for (m=0;cin>>a[m],a[m];++m);
	s[0]=0; F0R(i,m) s[i+1]=s[i]+a[i];
	dp.assign(m, vi(n+1, -1));
	ans=f(0,0);
	cout<<ans<<"\n";
	for (int u=0,port=0; u<ans; ++u) {
		if (ans==f(u+1, port)) cout<<"starboard\n";
		else { cout<<"port\n"; port+=a[u]; }
	}

	return 0;
}

/*
5000

2500 1500 700
3000 1000 1000

50
2500
3000
1000
1000
1500
700
800
0

2500 3000

*/