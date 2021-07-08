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
	freopen("guessthedatastructure.in", "r", stdin);

	int n;
	while(cin>>n, !cin.eof()) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		vi ans(3, 1);
		while (n--) {
			int op,u; cin>>op>>u;
			if (op==1) {
				s.push(u); q.push(u); pq.push(u);
				continue;
			}
			if (s.empty()) { ans[0]=ans[1]=ans[2]=0; continue; }
			if (ans[0] and s.top()!=u) ans[0]=0;
			if (ans[1] and q.front()!=u) ans[1]=0;
			if (ans[2] and pq.top()!=u) ans[2]=0;
			q.pop(); s.pop(); pq.pop();
		}
		int tot=ans[0]+ans[1]+ans[2];
		if (tot==0) cout<<"impossible\n";
		else if (tot>1) cout<<"not sure\n";
		else {
			if (ans[0]) cout<<"stack\n";
			else if (ans[1]) cout<<"queue\n";
			else if (ans[2]) cout<<"priority queue\n";
		}
	}

	return 0;
}