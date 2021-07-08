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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("nered.in", "r", stdin);

	int n,m; cin>>n>>m;
	vector<vi> g(n+1, vi(n+1, 0));
	F0R(i,m) {
		int y,x; cin>>y>>x;
		g[y][x]=1;
	}
	FOR(i, 1, n+1) 
		FOR(j, 1, n+1) 
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	int hi=0;
	FOR(c,1,m+1) {
		if (m%c) continue;
		int r = m/c;
		FOR(sy,1,n+1) {
			int ty=sy+r-1;
			if (ty>n) break;
			FOR(sx,1,n+1) {
				int tx=sx+c-1;
				if (tx>n) break;
				int sum=g[ty][tx] - g[ty][sx-1] - g[sy-1][tx] + g[sy-1][sx-1];
				hi=max(hi,sum);
			}
		}
	}
	cout<<m-hi;
	// for each rectangle
		// for each starting
		// save max
	// m - max

	return 0;
}