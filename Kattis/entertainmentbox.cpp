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
	freopen("entertainmentbox.in", "r", stdin);

	int n,k; cin>>n>>k;
	vii a(n); for (auto &[s,t]:a) cin>>s>>t;
	sort(a.begin(), a.end(), [](const ii &a, const ii&b) {
		if (a.second==b.second) return a.first > b.first;
		return a.second<b.second;
	});
	multiset<int> pq;
	int ans=0;
	for (auto &[s,t]:a) {
		auto it=pq.upper_bound(s);
		if (it!=pq.begin()) {
			pq.erase(--it); pq.insert(t); ++ans; continue;
		}
		if (pq.size()==k) continue;
		pq.insert(t); ++ans;
	}
	cout<<ans;

	return 0;
}