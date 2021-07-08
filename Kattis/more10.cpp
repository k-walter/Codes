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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("more10.in", "r", stdin);

	int n; cin>>n;
	vector<pair<string,string>> chk;
	vector<vector<string>> hzw(2);
	unordered_map<string,int> us;
	UnionFind uf(n<<1); int m=0;
	while (n--) {
		string u,op,v; cin>>u>>op>>v;
		int ulen=min((int)u.size(), 3);
		string ust=u.substr(u.size()-ulen, ulen);
		if (!us.count(ust)) {
			us[ust]=m++;
			if (ulen>1) hzw[ulen-2].pb(ust);
		}
		int vlen=min((int)v.size(), 3);
		string vst=v.substr(v.size()-vlen, vlen);
		if (!us.count(vst)) {
			us[vst]=m++;
			if (vlen>1) hzw[vlen-2].pb(vst);
		}
		if (op=="not") {
			chk.emplace_back(ust,vst); continue;
		}
		uf.unionSet(us[ust], us[vst]);
	}
	F0R(i,2) {
		FORr(u,hzw[i]) {
			// 0 --> 2 --> 1..
			// 1 --> 3 --> 1.., 2..
			FOR(j, 1, i+2) {
				string v = u.substr(j);
				if (!us.count(v)) continue;
				uf.unionSet(us[u], us[v]);
			}
		}
	}
	for (auto &[u,v]: chk)
		if (uf.isSameSet(us[u], us[v])) {
			cout<<"wait what?"; return 0;
		}
	cout<<"yes";
	

	return 0;
}

/*

3
oskar not lukas
oskar is poptart
lukas is smart

2
moo not foo
oo is blah

oo ah

moo foo
*/