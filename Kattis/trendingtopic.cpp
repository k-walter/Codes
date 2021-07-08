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
	freopen("trendingtopic.in", "r", stdin);

	string s;
	unordered_map<string,int> um[8];
	unordered_map<string,int> agg;
	set<pair<int,string>> os;
	int cur=0;
	while (cin>>s) {
		if (s=="<text>") continue; 
		if (s=="</text>") {
			int nex=(cur+1)&0b111;
			for (auto &[k,v]:um[nex]) {
				auto &vv = agg[k];
				assert(v>0 and vv>0 and vv>=v);
				os.erase({-vv, k});
				vv-=v;
				if (vv>0) os.emplace(-vv,k);
				else agg.erase(k);
			}
			um[nex].clear();
			for (auto &[k,v]:um[cur]) {
				assert(v>0);
				auto &vv = agg[k];
				if (vv) os.erase({-vv, k});
				vv+=v; os.emplace(-vv,k);
			}
			cur=nex;
			continue;
		}
		if (s!="<top") {
			if (s.size()>=4) ++um[cur][s];
			continue;
		}
		int n; cin>>n; cin>>s;
		int prv=-1e9;
		cout<<"<top "<<n<<">\n";
		for (auto &[hz,w]:os) {
			if (n--<=0) {
				if (hz!=prv) break;
			} else {
				prv=hz;
			}
			cout<<w<<" "<<-hz<<"\n";
		}
		cout<<"</top>\n";
	}

	return 0;
}