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
	freopen("ministryofmagic.in", "r", stdin);

	int c,p; cin>>c>>p;
	queue<int> q[p];
	vi v(p); int half=0;
	F0R(i, p) {
		cin>>v[i]; half+=v[i];
		F0R(j, c) {
			int u; cin>>u;
			q[i].push(u-1);
		}
	}
	half>>=1;
	vi vis(c,0); int VIS=0;
	vi vote(c);
	for (int rem=c; rem>1;) {
		// count votes
		++VIS;
		F0R(i, p) {
			auto &qq = q[i];
			while (vis[qq.front()]==-1) qq.pop();
			if (vis[qq.front()]!=VIS) {
				vis[qq.front()]=VIS; vote[qq.front()]=0;
			}
			vote[qq.front()]+=v[i];
		}
		// check majority
		F0R(i, c) {
			if (vis[i]!=VIS) continue;
			if (vote[i]<=half) continue;
			cout<<i+1; return 0;
		}
		// remove minority
		int lo=1e9, mi=-1;
		F0R(i, c) {
			if (vis[i]==-1) continue;
			if (vis[i]!=VIS) { vis[i]=-1; --rem; }
			else if (vote[i]<lo) { lo=vote[i]; mi=i; }
		}
		if (mi!=-1) { vis[mi]=-1; --rem; }
	}
	F0R(i, c) {
		if (vis[i]==-1) continue;
		cout<<i+1; return 0;
	}

	return 0;
}
