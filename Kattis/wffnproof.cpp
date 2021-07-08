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
#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define F0R(i, a) for (int i = 0; i < (int)(a); i++)
#define FORd(i,a,b) for (int i = (int)(a)-1; i >= (b); i--)
#define F0Rd(i,a) for (int i = (int)(a)-1; i >= 0; i--)
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
	freopen("wffnproof.in", "r", stdin);

	string T;
	while (cin>>T, T != "0") {
		// prefix
		int N=0;
		std::vector<char> pqrst, KACE;
		for (char &c:T) {
			switch(c) {
				case 'p': case 'q': case 'r': case 's': case 't':
					pqrst.push_back(c); break;
				case 'N': ++N; break;
				case 'K': case 'A': case 'C': case 'E':
					KACE.push_back(c); break;
			}
		}
		if (pqrst.empty()) {
			cout<<"no WFF possible\n";
			continue;
		}
		string pre = "", suf="";
		while (N--) pre+="N";
		suf += pqrst.back();
		pqrst.pop_back();
		while (pqrst.size() and KACE.size()) {
			pre += KACE.back();
			suf += pqrst.back();
			pqrst.pop_back(); KACE.pop_back();
		}
		cout<<pre<<suf<<"\n";
		// if no start, no WFF
		// put all N
		// put 1st
		// while KACE and pqrst
			// put both
	}

	return 0;
}

/*
pqrst
w --> Nw
w, x --> [KACE]wx

NNNNpKNNNNq
pqr
*/