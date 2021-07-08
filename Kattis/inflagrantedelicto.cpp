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

class SuffixArray {
public:
  vi RA;                                         // rank array

  void countingSort(int k) {                     // O(n)
    int maxi = max(300, n);                      // up to 255 ASCII chars
    vi c(maxi, 0);                               // clear frequency table
    for (int i = 0; i < n; ++i)                  // count the frequency
      ++c[i+k < n ? RA[i+k] : 0];                // of each integer rank
    for (int i = 0, sum = 0; i < maxi; ++i) {
      int t = c[i]; c[i] = sum; sum += t;
    }
    vi tempSA(n);
    for (int i = 0; i < n; ++i)                  // sort SA
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    swap(SA, tempSA);                            // update SA
  }

  void constructSA() {                           // can go up to 400K chars
    SA.resize(n);
    iota(SA.begin(), SA.end(), 0);               // the initial SA
    RA.resize(n);
    for (int i = 0; i < n; ++i) RA[i] = T[i];    // initial rankings
    for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
      // this is actually radix sort
      countingSort(k);                           // sort by 2nd item
      countingSort(0);                           // stable-sort by 1st item
      vi tempRA(n);
      int r = 0;
      tempRA[SA[0]] = r;                         // re-ranking process
      for (int i = 1; i < n; ++i)                // compare adj suffixes
        tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
          ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k])) ?
            r : ++r;
      swap(RA, tempRA);                          // update RA
      if (RA[SA[n-1]] == n-1) break;             // nice optimization
    }
  }

  void computeLCP() {
    vi Phi(n);
    vi PLCP(n);
    PLCP.resize(n);
    Phi[SA[0]] = -1;                             // default value
    for (int i = 1; i < n; ++i)                  // compute Phi in O(n)
      Phi[SA[i]] = SA[i-1];                      // remember prev suffix
    for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
      if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
      while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L]))
        ++L;                                     // L incr max n times
      PLCP[i] = L;
      L = max(L-1, 0);                           // L dec max n times
    }
    LCP.resize(n);
    for (int i = 0; i < n; ++i)                  // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];                      // restore PLCP
  }

  // const char* T;                                 // the input string
  const vi T;                                 // the input string
  const int n;                                   // the length of T
  vi SA;                                         // Suffix Array
  vi LCP;                                        // of adj sorted suffixes

  SuffixArray(vi initialT, const int _n) : T(initialT), n(_n) {
    constructSA();                               // O(n log n)
    computeLCP();                                // O(n)
  }
};


int n;
vi T,P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("inflagrantedelicto.in", "r", stdin);

	cin >> n;
	T.resize(n); FORr(i,T) cin>>i;
	P.resize(n); FORr(i,P) cin>>i;
	// find smallest diff
	vi TP(2*(n+1));
	F0R(i,n) TP[i]=T[i];
	TP[n]=0;
	F0R(i,n) TP[n+1+i]=P[i];
	TP[2*n+1]=0;
	SuffixArray sa(TP, 2*(n+1));
	int kp = n, hz[]={0,0};
	int L=0;
	F0R(i, 2*n+1) {
		// add current
		int idx = sa.SA[i];
		if (idx <= n) ++hz[0];
		else ++hz[1];
		if (!(hz[0] and hz[1])) continue;
		// find differing internal node
		while (L<=i and hz[0] and hz[1]) {
			if (sa.SA[L] <= n) --hz[0];
			else --hz[1];
			++L;
		}
		int lo = n;
		FOR(j, L, i+1) {
			lo = min(lo, sa.LCP[j]);
		}
		lo = max(lo, 1);
		kp = min(lo, kp);
	}
	// find length where all combinations different
	// = find length where no common
	// = longest common subsequence + 1
	// = LIS unique + 1
	int lut[n+1];
	F0R(i,n) lut[T[i]]=i;
	FORr(i,P) i=lut[i];
	// lis
	int k = 0, lis_end = 0;
	vi LIS(n, 0);

	for (int i = 0; i < n; ++i) {                  // O(n)
    int pos = lower_bound(LIS.begin(), LIS.begin()+k, P[i]) - LIS.begin();
    LIS[pos] = P[i];                               // greedily overwrite this
    if (pos == k) {                              // can extend LIS?
      k = pos+1;                                 // k = longer LIS by +1
      lis_end = i;                               // keep best ending i
    }
}
    // ans
	cout<<(kp+1)<<' '<<k+1;

	return 0;
}