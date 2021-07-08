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
	freopen("fridge.in", "r", stdin);

	string line; getline(cin, line);
	int hz[10]; memset(hz, 0, sizeof hz);
	FORr(c,line) ++hz[c-'0'];
	int lo=1e9, dig;
	F0R(i, 10) {
		int off=i==0;
		if (hz[i]+off >= lo) continue;
		lo=hz[i]+off; dig=i;
	}
	if (dig==0) { cout<<1; --lo; }
	F0R(i,lo+1) cout<<dig;

	return 0;
}

/*
missing 2-9
1..12

0 to 2 only
0011
	2
21100
	22
2100
	11
210
	11
01122
	100
0122
	11
*/