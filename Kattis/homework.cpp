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

const int MAXN = 5000;
bitset<MAXN> vis[MAXN];
bool dp[MAXN][MAXN];
string S,T,U; 

bool f(int i=0, int j=0) {
	int u = i + j;
	// cout<<i<<" + "<<j<<" = "<<u<<"\n";
	if (u == S.size()) return 1;
	auto &ans = dp[i][j];
	if (vis[i][j]) return ans;
	ans = 0; vis[i][j] = 1;
	if (i < T.size() and T[i]==S[u]) ans = f(i+1, j);
	if (ans) return ans;
	if (j < U.size() and U[j]==S[u]) ans = f(i, j+1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("homework.in", "r", stdin);

	cin>>S>>T>>U;
	// same character set
	int hz[26]; memset(hz, 0, sizeof hz);
	FORr(c,S) ++hz[c-'a'];
	FORr(c,T) --hz[c-'a'];
	FORr(c,U) --hz[c-'a'];
	F0R(i,26) if (hz[i]) { cout<<"no"; return 0; }
	// both are LCS
	cout<<(f(0, 0) ? "yes" : "no");


	return 0;
}