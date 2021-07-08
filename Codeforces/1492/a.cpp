#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
#define FOR(i,j) for(int i=0;i<j;++i)

void solve() {
	ll p,a,b,c; cin>>p>>a>>b>>c;
	ceil(a-1);
	a = (a + p) % p;
	b = (b + p) % p;
	c = (c + p) % p;
	cout<<min(min(a,b), c)<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("a.in", "r", stdin);

	int tc; cin>>tc;
	// while (tc--) solve();
	FOR(a,10){
		cout<<a<<"\n";
	}

	return 0;
}