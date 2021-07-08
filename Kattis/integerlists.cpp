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
	string op; cin>>op;
	int n; cin>>n; cin.get();
	deque<string> q;
	string line; getline(cin,line);
	stringstream ss=stringstream(line.substr(1, line.size()-2));
	while(n--) { string s; getline(ss,s,','); q.pb(s); }
	bool rev=0;
	FORr(c,op) {
		if (c=='R') rev=!rev;
		else {
			if (q.empty()) { cout<<"error\n"; return; }
			if (rev) q.pop_back();
			else q.pop_front();
		}
	}
	cout<<"[";
	if (rev) reverse(q.begin(), q.end());
	F0R(i,q.size()) {
		if (i) cout<<",";
		cout<<q[i];
	}
	cout<<"]\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("integerlists.in", "r", stdin);

	int tc; cin>>tc;
	while(tc--) solve();

	return 0;
}