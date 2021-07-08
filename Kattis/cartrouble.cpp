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

enum {NEW, VIS};
bitset<1001> unr, trp;
vector<vi> al(1001), la(1001);
void dfs(int u) {
	if (unr[u] == VIS) return;
	unr[u] = VIS;
	FORr(v,al[u]) {
		dfs(v);
	}
}

void dfs2(int u) {
	if (trp[u] == VIS) return;
	trp[u] = VIS;
	FORr(v,la[u]){
		dfs2(v);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("cartrouble.in", "r", stdin);

	int V; cin>>V;
	vi ans(V);
	FORr(u,ans){
		int i; cin>>u>>i;
		while (i--) { int v; cin>>v;
			al[u].pb(v);
			la[v].pb(u);
		}
	}
	dfs(0); dfs2(0);
	bool ok=1;
	FORr(u,ans){
		if (trp[u]==VIS or u==0) continue;
		ok=0; cout<<"TRAPPED "<<u<<"\n";
	}
	FORr(u,ans){
		if (unr[u]==VIS or u==0) continue;
		ok=0; cout<<"UNREACHABLE "<<u<<"\n";
	}
	if (ok) cout<<"NO PROBLEMS";

	return 0;
}