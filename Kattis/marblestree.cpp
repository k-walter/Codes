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
	freopen("marblestree.in", "r", stdin);

	int n;
	while (cin>>n, n) {
		vi no(n), in(n,0), al(n,-1);
		F0R(u,n) {
			int m; cin>>m>>no[u]>>m;
			while (m--) {
				int v; cin>>v; --v;
				al[v]=u; ++in[u];
			}
		}
		queue<int> q;
		F0R(u,n) if (in[u]==0)
			q.push(u);
		int ans=0;
		while (q.size()) {
			int u = q.front(); q.pop();
			int v = al[u];
			if (v==-1) continue;
			int trf = no[u]-1;
			ans += abs(trf);
			no[v] += trf;
			if (--in[v]==0) q.push(v);
		}
		cout<<ans<<"\n";
	}

	return 0;
}