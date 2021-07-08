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

inline void solve() {
	int n; cin>>n;
	priority_queue<ii> buy;
	priority_queue<ii, vii, greater<ii>> sell;
	int stk=-1;
	while (n--) {
		string op; cin>>op;
		int amt; cin>>amt;
		string foo; cin>>foo>>foo;
		int prc; cin>>prc;
		if (op=="buy") {
			while (amt>0 and sell.size() and prc>=sell.top().first) {
				auto [vp,va] = sell.top(); sell.pop();
				stk=vp;
				if (va>amt) sell.emplace(vp,va-amt);
				amt -= min(amt,va);
			}
			if (amt>0) buy.emplace(prc,amt);
		} else {
			// check buys
			while (amt>0 and buy.size() and prc<=buy.top().first) {
				auto [vp,va] = buy.top(); buy.pop();
				stk=prc;
				if (va>amt) buy.emplace(vp,va-amt);
				amt -= min(amt,va);
			}
			if (amt>0) sell.emplace(prc,amt);
		}
		if (sell.empty()) cout<<"-";
		else cout<<sell.top().first;
		cout<<" ";
		if (buy.empty()) cout<<"-";
		else cout<<buy.top().first;
		cout<<" ";
		if (stk==-1) cout<<"-";
		else cout<<stk;
		cout<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("stockprices.in", "r", stdin);

	int t; cin>>t;
	while(t--) solve();

	return 0;
}
/*
buy >= sell

Sell 	Buy 	Last
10*100
		1*80
		(20*90)
(10*90)
		(10*101)
1*80

buy
	from smallest seller
sell
	from biggest buyer
end
	smallest seller
	biggest buyer


100 - -
100 80 -
100 90 -
90 80 90
100 80 90
100 - 80

sell 	Buy 	last
		10*100
1*120
(20*110)
		(10)*110
10*99

- 100 -
120 100 -
110 100 -
120 110 110
120 100 99
- 100 120


*/