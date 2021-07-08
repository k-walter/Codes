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
#define FOR(i, T, P) for (int i = (T); i < (P); i++)
#define F0R(i, T) for (int i = 0; i < (T); i++)
#define FORd(i,T,P) for (int i = (T)-1; i >= (P); i--)
#define F0Rd(i,T) for (int i = (T)-1; i >= 0; i--)
#define FORr(T, x) for (auto& T : x)
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

const int MAX_N = 8;
vi T,P; int n, m;

// Knuth-Morris-Pratt's algorithm specific code
int b[MAX_N];                                    // b = back table
void kmpPreprocess() {                           // call this first
  int i = 0, j = -1; b[0] = -1;                  // starting values
  while (i < m) {                                // pre-process P
    while ((j >= 0) && (P[i] != P[j])) j = b[j]; // different, reset j
    ++i; ++j;                                    // same, advance both
    b[i] = j;
  }
}

int kmpSearch() {                               // similar as above
  int freq = 0;
  int i = 0, j = 0;                              // starting values
  while (i < n) {                                // search through T
    while ((j >= 0) && (T[i] != P[j])) j = b[j]; // if different, reset j
    ++i; ++j;                                    // if same, advance both
    if (j == m) {                                // a match is found
      ++freq;
      // printf("P is found at index %d in T\n", i-j);
      j = b[j];                                  // prepare j for the next
    }
  }
  return freq;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("clockpictures.in", "r", stdin);

	cin>>n;
	T.resize(n); FORr(i,T) cin>>i;
	P.resize(n); FORr(i,P) cin>>i;
	sort(T.begin(), T.end());
	sort(P.begin(), P.end());
	int sa = (T[0] - T.back() + 360000) % 360000;
	int sb = (P[0] - P.back() + 360000) % 360000;
	FOR(i, 1, n) {
		T[i-1] = T[i] - T[i-1];
		P[i-1] = P[i] - P[i-1];
	}
	T[n-1]=sa; P[n-1]=sb;
	m=n; n<<=1;
	F0R(i,m) T.pb(T[i]);
	kmpPreprocess();
	cout << (kmpSearch() ? "possible" : "impossible");

	return 0;
}