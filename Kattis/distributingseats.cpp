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
typedef pair<int,int> ii;
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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("distributingseats.in", "r", stdin);

	int n,r,c; cin>>n>>r>>c;
	vii a(n);
	for (auto &[s,t]:a){
		int y,x,w;cin>>y>>x>>w;
		s=y-w; t=-(y+w);
	}	
	sort(a.begin(), a.end());
	int ans=0;
	priority_queue<int> pq; int j=0;
	FOR(i,1,r+1){
		while (j<a.size() and a[j].first<=i) {
			pq.push(a[j].second);
			++j;
		}
		// cout<<pq.size()<<"\n";
		F0R(j,c){
			while (pq.size() and -pq.top()<i) pq.pop();
			if (pq.empty()) break;
			pq.pop(); ++ans;
		}
	}
	cout<<ans;

	return 0;
}