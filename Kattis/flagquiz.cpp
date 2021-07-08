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
	freopen("flagquiz.in", "r", stdin);

	string line; getline(cin,line);
	int n; cin>>n; cin.get();
	std::vector<vector<string>> a(n);
	vector<string> og(n);
	F0R(i,n) {
		getline(cin,og[i]);
		stringstream ss=stringstream(og[i]);
		string s;
		while (getline(ss,s,',')) a[i].pb(s);
	}
	vi ans(n,0);
	F0R(i,n-1) {
		auto &u=a[i];
		FOR(j,i+1,n) {
			auto &v=a[j];
			int dif=0;
			F0R(k,u.size()) {
				if (u[k]!=v[k]) ++dif;
			}
			ans[i]=max(ans[i],dif);
			ans[j]=max(ans[j],dif);
		}
	}
	int hi=1e9;
	FORr(i,ans) hi=min(hi,i);
	F0R(i,n) {
		if (ans[i]!=hi) continue;
		cout<<og[i]<<"\n";
	}

	return 0;
}