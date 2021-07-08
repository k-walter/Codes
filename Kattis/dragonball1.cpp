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
typedef tuple<ll,int,int> iii;
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
	freopen("dragonball1.in", "r", stdin);

	int n,m; cin>>n>>m;
	vector<vii> al(n);
	while(m--){
		int u,v,w; cin>>u>>v>>w; --u; --v;
		al[u].emplace_back(v,w);
		al[v].emplace_back(u,w);
	}
	vi ball(n,0); F0R(i,7) {
		int u; cin>>u; ball[u-1]|=1<<i;
	}
	queue<int> q; vector<bool> vis(n,0);
	q.push(0); vis[0]=1; int ok=ball[0];
	while(ok!=(1<<7)-1 and q.size()) {
		int &u=q.front();
		for (auto &[v,_]:al[u]) {
			if (vis[v]) continue;
			vis[v]=1; q.push(v); ok|=ball[v];
		}
		q.pop();
	}
	if (ok!=(1<<7)-1) {
		cout<<-1; return 0;
	}
	vector<vll> dist(n, vll(1<<7, INF));
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	dist[0][ball[0]]=0; pq.emplace(0,ball[0],0); // dist,ball,vtx
	while (pq.size()) {
		auto [d,b,u]=pq.top(); pq.pop();
		if (d>dist[u][b]) continue;
		// cout<<"dist "<<d<<" ball "<<__builtin_popcount(b)<<" vtx "<<u<<"\n";
		if (b==(1<<7)-1) {
			cout<<d; return 0;
		}
		for (auto &[v,w]:al[u]) {
			int bb=b|ball[v];
			if (d+w >= dist[v][bb]) continue;
			dist[v][bb]=d+w; pq.emplace(d+w, bb, v);
		}
	}
	cout<<-1;

	return 0;
}