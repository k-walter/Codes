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

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize, lut;                           // vi p is the key part
  vll setSum;
  int nextFree;
public:
  UnionFind(int N, int m) : nextFree(N) {
  	p.resize(N+m); iota(p.begin(), p.end(), 0);
  	lut.resize(N+1); iota(lut.begin(), lut.end(),-1);
    setSum.resize(N+m, 0); for (int i=0;i<N;++i) setSum[i]=i+1;
    rank.assign(N+m, 0);
    setSize.assign(N+m, 1);                        // optional feature
  }
  int findSet(int i) {
  	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
  	return findSet(i) == findSet(j);
  }
  int sizeOfSet(int i) {
  	return setSize[findSet(lut[i])];
  }
  ll sumOfSet(int i) {
  	return setSum[findSet(lut[i])];
  }
  void unionSet(int p, int q) {
  	_unionSet(lut[p], lut[q]);
  }
  void _unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    setSum[y] += setSum[x];
  }
  void moveSet(int p, int q) {
  	if (isSameSet(lut[p], lut[q])) return;
  	int prv = findSet(lut[p]);
  	setSum[prv]-=p; --setSize[prv];
  	setSum[nextFree]=p; lut[p]=nextFree; 
  	_unionSet(nextFree, lut[q]);
  	++nextFree;
  }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("almostunionfind.in", "r", stdin);

	int n,m;
	while (cin>>n) {
		cin>>m;
		UnionFind uf(n,m);
		while (m--) {
			int op; cin>>op;
			switch(op) {
			case 1:{
				int p,q; cin>>p>>q;
				uf.unionSet(p,q);
				break;
			}
			case 2:{
				int p,q; cin>>p>>q;
				uf.moveSet(p,q);
				break;
			}
			case 3:{
				int p; cin>>p;
				cout<<uf.sizeOfSet(p)<<" "<<uf.sumOfSet(p)<<"\n";
				break;
			}
			}
		}
	}

	return 0;
}