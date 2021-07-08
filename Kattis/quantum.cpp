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
#define eb emplace_back
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
typedef tuple<int,int,int,int> iiii;
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

void solve() {
	int n,o,tc; cin>>n>>o>>tc;
	vector<iiii> al(o);
	for(auto &[f,s,c,w]:al){
		string op; cin>>op>>w;
		f=s=c=0;
		FORr(ch,op){
			f<<=1;
			s<<=1;
			c<<=1;
			switch(ch){
				case 'F': f|=1; break;
				case 'S': s|=1; break;
				case 'C': c|=1; break;
			}
		}
		c=~c;
	}
	while (tc--) {
		string ss,tt; cin>>ss>>tt;
		int s,t; s=t=0;
		FORr(ch,ss){ s<<=1; if(ch=='1') s|=1; }
		FORr(ch,tt){ t<<=1; if(ch=='1') t|=1; }
		priority_queue<ii,vii,greater<ii>> pq; pq.emplace(0,s);
		unordered_map<int,int> dist; dist[s]=0;
		while (pq.size()) {
			auto [d,u] = pq.top(); pq.pop();
			if (d > dist[u]) continue;
			if (u == t) break;
			for(auto &[f,s,c,w]:al){
				auto v = (((u|s)&c)^f);
				if (dist.count(v) and dist[v]<=d+w) continue;
				dist[v] = d+w; pq.emplace(d+w, v);
			}
		}
		if (dist.count(t)) cout<<dist[t];
		else cout<<"NP";
		cout<<" ";
	}
	cout<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("quantum.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) solve();

	return 0;
}