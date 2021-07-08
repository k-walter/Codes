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

int c,n;
ii a[2000];
int dp[2000][2001], vis[2000][2001], VIS=-1;

int f(int u, int cap) {
	if (u==n) return 0;
	int &ans=dp[u][cap];
	if (vis[u][cap]==VIS) return ans;
	vis[u][cap]=VIS;
	auto &[v,w]=a[u];
	ans=f(u+1,cap);
	if (cap+w<=c) ans=max(ans, v+f(u+1, cap+w));
	return ans;
}

void solve() {
	++VIS;
	cin>>c>>n;
	F0R(i,n) {
		auto &[v,w]=a[i];
		cin>>v>>w;
	}
	int u=0,cap=0;
	int ans=f(0,0);
	vi arr;
	while (vis[u][cap]==VIS) {
		if (f(u+1,cap)==ans) {
			if (++u==n) break;
			continue;
		}
		auto &[v,w]=a[u];
		arr.pb(u); ans-=v; ++u; cap+=w;
		if (u==n) break;
	}
	cout<<arr.size()<<"\n";
	FORr(i,arr) cout<<i<<" "; cout<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("knapsack.in", "r", stdin);

	memset(vis,-1,sizeof vis);
	while(!cin.eof()) solve();

	return 0;
}