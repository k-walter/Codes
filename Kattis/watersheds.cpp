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
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

int g[100][100];
char ass[10000]; int vis[10000], VIS=-1;
int dy[]={-1,0,0,1}, dx[]={0,-1,1,0};

inline void solve() {
	int r,c; cin>>r>>c;
	UnionFind uf(r*c);
	F0R(i,r) F0R(j,c) cin>>g[i][j];
	F0R(i,r) F0R(j,c) {
		int lo=g[i][j], yy=-1, xx=-1;
		F0R(k,4) {
			int y=i+dy[k], x=j+dx[k];
			if (y<0 or y>=r or x<0 or x>=c) continue;
			if (g[y][x]>=lo) continue;
			lo=g[y][x]; yy=y; xx=x;
		}
		if (yy==-1) continue;
		int u=c*i+j, v=c*yy+xx;
		uf.unionSet(u,v);
	}
	char no='a';
	F0R(i,r) {
		F0R(j,c) {
			int u=uf.findSet(c*i+j);
			if (vis[u]!=VIS) {
				vis[u]=VIS; ass[u]=no++;
			}
			cout<<ass[u]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("watersheds.in", "r", stdin);

	memset(vis, -1, sizeof vis);
	int t; cin>>t;
	FOR(i,1,t+1) {
		cout<<"Case #"<<i<<":\n";
		++VIS; solve();
	}

	return 0;
}