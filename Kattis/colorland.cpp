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

typedef tuple<int,int,int,int,int,int> col;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("colorland.in", "r", stdin);

	int n; cin>>n;
	vector<vi> next(n+1, vi(6, -1));
	FOR(i, 1, n+1) {
		string s; cin>>s;
		int j;
		switch(s[0]) {
			case 'B': j=0; break;
			case 'O': j=1; break;
			case 'P': j=2; break;
			case 'G': j=3; break;
			case 'R': j=4; break;
			case 'Y': j=5; break;
		}
		next[i][j]=i;
	}
	vi nex(next[n]);
	F0Rd(i, n) {
		F0R(j, 6) {
			if (next[i][j]==-1) next[i][j]=nex[j];
			else swap(nex[j], next[i][j]);
		}
	}
	// for (int &i : next[5]) cout<<i<<" "; cout<<"\n";
	int ans = 0;
	for (int i=0, j=-1; i < n; i=j, j=-1) {
		// cout<<i<<"\n";
		F0R(k, 6) {
			j=max(j, next[i][k]);
		}
		++ans;
	}
	cout<<ans;

	return 0;
}