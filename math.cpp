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

const ll MAX_N = 1e7;
int p = 1e9+7;

/* Prime */

bitset<MAX_N> bs; ll sieve_size;
vll prime;
vll SPF(MAX_N, 0); // smallest prime factor

inline void sieve(int N) {
	bs.set(); bs[0] = bs[1] = 0;
	sieve_size = N + 1;
	for (ll i=2; i<N; ++i) {
		if (bs[i]) {
			prime.push_back(i);
			SPF[i] = i;
		}
		// for all primes <= SPF[i]
		for (ll &j : prime) {
			if (i * j >= N) break;
			if (j > SPF[i]) break;
			// mark as non-prime
			bs[i*j] = 0;
			// save smallest prime factor
			SPF[i*j] = j;
		}
	}
}

// Works up to N <= last prime ^ 2
bool isPrime(ll N) {
	if (N < sieve_size) return bs[N];
	for (ll &p : prime)
		if (N % p == 0)
			return 0;
	return 1;
}

vll primeFactors(ll N) {                         // pre-condition, N >= 1
  vll factors;
  for (int i = 0; i < (int)prime.size() && prime[i]*prime[i] <= N; ++i)
    while (N%prime[i] == 0) {                        // found a prime for N
      N /= prime[i];                                 // remove it from N
      factors.push_back(prime[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)prime.size() && prime[i]*prime[i] <= N; ++i)
    while (N%prime[i] == 0) { N /= prime[i]; ++ans; }
  return ans + (N != 1);
}

int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < prime.size() && prime[i]*prime[i] <= N; ++i) {
    if (N%prime[i] == 0) ++ans;                      // count this prime factor
    while (N%prime[i] == 0) N /= prime[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}

ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < prime.size() && prime[i]*prime[i] <= N; ++i)
    while (N%prime[i] == 0) { N /= prime[i]; ans += prime[i]; }
  if (N != 1) ans += N;
  return ans;
}

int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)prime.size() && prime[i]*prime[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%prime[i] == 0) { N /= prime[i]; ++power; }
    ans *= power+1;                              // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

ll sumDiv(ll N) {
  ll ans = 1;                                    // start from ans = 1
  for (int i = 0; i < (int)prime.size() && prime[i]*prime[i] <= N; ++i) {
    ll multiplier = prime[i], total = 1;
    while (N%prime[i] == 0) {
      N /= prime[i];
      total += multiplier;
      multiplier *= prime[i];
    }                                            // total for
    ans *= total;                                // this prime factor
  }
  if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
  return ans;
}

ll EulerPhi(ll N) {
  ll ans = N;                                    // start from ans = N
  for (int i = 0; i < (int)prime.size() && prime[i]*prime[i] <= N; ++i) {
    if (N%prime[i] == 0) ans -= ans/prime[i];            // count unique
    while (N%prime[i] == 0) N /= prime[i];               // prime factor
  }
  if (N != 1) ans -= ans/N;                      // last factor
  return ans;
}


/* Modulo */

inline ll mod(ll a, int m) {                            // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

inline ll modPow(ll b, int p, int m) {                  // assume 0 <= b < m
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);                    // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}


int crt(vi r, vi m) {
	// mt = m0 * m1 * ... * m_(n-1)
	int mt = accumulate(m.begin(), m.end(), 1, multiplies<>());
	int x = 0;
	for (int i = 0; i < m.size(); ++i) {
		int a = mod((ll)r[i] * modInverse(mt/m[i], m[i]), m[i]);
		x = mod(x + (ll)a * (mt/m[i]), mt);
	}
	return x;
}

/* Combinatorial */

ll fact[MAX_N], invFact[MAX_N];
ll Fib[MAX_N], Cat[MAX_N];

ll inv(ll a) {                                   // Fermat's little theorem
  return modPow(a, p-2, p);                      // modPow in Section 5.8
}                                                // that runs in O(log p)

// Combination
inline ll C(int n, int k) {                             // O(log p)
  if (n < k) return 0;                           // clearly
  return (((fact[n] * inv(fact[k])) % p) * inv(fact[n-k])) % p;
  // return (((fact[n] * invFact[k]) % p) * invFact[n-k]) % p; // O(1)
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(".in", "r", stdin);

	sieve(1e6); //for (ll &i:prime) cout<<i<<" ";

	return 0;
}
