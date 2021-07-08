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

inline void solve() {
	int n,m; cin>>n>>m;
	unordered_map<string,tuple<int,int,int>> car;
	// each car
	F0R(i,n) {
		string s; int p,q,k;
		cin>>s>>p>>q>>k; car[s]={p,q,k};
	}
	// each event
	map<string,ll> spy;
	unordered_map<string,pair<int,int>> rent;
	while (m--) {
		int t; string s,op; cin>>t>>s>>op;
		switch (op[0]) {
		case 'p': {
			string c; cin>>c;
			if (spy[s]==-1) break;
			if (rent.count(s)) { //  or !car.count(c)
				spy[s]=-1; rent.erase(s);
				break;
			}
			auto &[p,q,k]=car[c];
			rent[s]={p,k};
			spy[s]+=q;
			break;
		}
		case 'r': {
			int d; cin>>d;
			if (spy[s]==-1) break;
			if (!rent.count(s)) {
				spy[s]=-1; break;
			}
			auto &[p,k]=rent[s];
			spy[s]+=k*d;
			rent.erase(s);
			break;
		}
		case 'a': {
			double c; cin>>c;
			if (!rent.count(s)) {
				spy[s]=-1; break;
			}
			auto &[p,k]=rent[s];
			spy[s]+=ceil(c*p/100);
			break;
		}
		}
	}
	for (auto &[s,v]: rent) spy[s]=-1;
	for (auto &[s,c]:spy) {
		cout<<s<<" ";
		if (c==-1) cout<<"INCONSISTENT";
		else cout<<c;
		cout<<"\n";
	}
		// if inconsistent, ignore
		// check if consistent
		// pickup: is spy using another?
			// add pickup cost
		// accident: did spy pickup b4?
			// mla accident cost
		// return: did spy pickup?
			// mla distance * ..k.
	// check all cars returned
	// each person
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("administrativeproblems.in", "r", stdin);

	int t; cin>>t; while(t--) solve();

	return 0;
}