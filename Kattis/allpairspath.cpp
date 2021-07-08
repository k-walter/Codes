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
const int INF=1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("allpairspath.in", "r", stdin);

	int n,m,q;
	int am[150][150];
	while (cin>>n>>m>>q, n or m or q) {
		F0R(u,n) F0R(v,n) am[u][v]=INF;
		F0R(u,n) am[u][u]=0;
		while (m--) {
			int u,v,w; cin>>u>>v>>w;
			am[u][v]=min(am[u][v],w);
		}
		F0R(i,n) {
			F0R(u,n) {
				F0R(v,n) {
					if (am[u][i]==INF or am[i][v]==INF) continue;
					am[u][v]=min(am[u][v], am[u][i]+am[i][v]);
				}
			}
		}
		F0R(i,n) {
			if (am[i][i]>=0) continue;
			F0R(u,n) {
				F0R(v,n) {
					if (am[u][i]==INF or am[i][v]==INF) continue;
					am[u][v]=-INF;
				}
			}
		}
		while(q--) {
			int u,v; cin>>u>>v;
			if (am[u][v]==INF) cout<<"Impossible\n";
			else if (am[u][v]==-INF) cout<<"-Infinity\n";
			else cout<<am[u][v]<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}