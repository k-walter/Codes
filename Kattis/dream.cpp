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
	freopen("dream.in", "r", stdin);

	int n,m,l,h; cin>>n;
	unordered_map<string,int> E;
	stack<string> s;
	F0R(i,n) {
		string op; cin>>op;
		switch(op[0]) {
			case 'S':
				l=-1e9,h=-1e9;
				cin>>m; while(m--) {
					string f; cin>>f;
					if (l==-2) continue;
					if (f[0]!='!') {
						if (!E.count(f)) l=-2;
						h=max(h, (int)s.size()-E[f]);
					} else {
						f=f.substr(1);
						if (E.count(f)) l=max(l,(int)s.size()-E[f]); 
					}
				}
				if (l==-2 or (h!=-1e9 and l!=-1e9 and h<=l)) cout<<"Plot Error\n";
				else if (l==-1e9) cout<<"Yes\n";
				else cout<<l<<" Just A Dream\n";
				break;
			case 'E':
				cin>>op;
				E[op]=s.size();
				s.push(op);
				break;
			case 'D':
				cin>>l;
				while (l--) {
					string f=s.top();
					E.erase(f);
					s.pop();
				}
				break;
		}
	}

	return 0;
}
/*
10
E business_as_usual
E bobby_dies
S 1 bobby_died --> Plot Error
E stuff_happens
E jr_does_bad_things
S 2 !bobby_dies business_as_usual
E it_goes_on_and_on
D 4
S 1 !bobby_dies
S 2 !bobby_dies it_goes_on_and_on

plot error
	e not in events
just a dream
	save lowest r + 1
yes
	
*/