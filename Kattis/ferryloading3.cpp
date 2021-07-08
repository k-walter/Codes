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
	int n,t,m; cin>>n>>t>>m;
	queue<tuple<int,int,bool>> q;
	vi ans(m);
	F0R(i, m) {
		int t; string s; cin>>t>>s;
		q.emplace(t, i, s[0]=='l');
	}
	int ti=0, lef=1;
	queue<int> qs[2];
	while (q.size() or qs[0].size() or qs[1].size()) {
		if (qs[0].empty() and qs[1].empty())
			ti = max(ti, get<0>(q.front()));
		while (q.size() and get<0>(q.front()) <= ti) {
			auto &[t,i,s] = q.front();
			qs[s].push(i);
			q.pop();
		}
		ti+=t;
		F0R(i,n) {
			if (qs[lef].empty()) break;
			int &j = qs[lef].front();
			ans[j]=ti;
			qs[lef].pop();
		}
		lef=!lef;
	}
	FORr(i,ans) cout<<i<<"\n"; 
	cout<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("ferryloading3.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) solve();

	return 0;
}

/*
2
2 10 10

0 left
	>> right = 10
	<< left = 10

10 left
20 left
	>><<
30 left
40 left
	>><<
50 left
60 left

70 left
80 left

90 left

2 10 3
10 right
25 left
40 left

*/