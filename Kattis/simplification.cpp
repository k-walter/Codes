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

int n, m;

struct point_i {
  int x, y;                                      // use this if possible
  point_i() { x = y = 0; }                       // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

struct vec_i { int x, y;  // name: `vec' is different from STL vector
  vec_i(int _x, int _y) : x(_x), y(_y) {} };

vec_i toVec(point_i a, point_i b) {       // convert 2 points to vector a->b
  return vec_i(b.x-a.x, b.y-a.y); }

ll cross(vec_i a, vec_i b) { return a.x*b.y - a.y*b.x; }

ll area(point_i a, point_i b, point_i c) {
	vec_i ab = toVec(a, b), bc = toVec(b, c);
	return llabs(cross(ab, bc)); // * 2 // removed to keep in ll
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("simplification.in", "r", stdin);

	cin >> n >> m; ++n;
	vector<point_i> a(n);
	for (auto &p : a) {
		cin >> p.x >> p.y; 
	}
	vi left(n), right(n);
	F0R(i, n) { left[i] = i-1; right[i] = i+1; }
	set<pair<ll, int>> pq;
	vector<ll> ar(n);
	FOR(i, 1, n-1) {
		auto aa = area(a[i-1], a[i], a[i+1]);
		// cout << i << " " << aa << "\n";
		ar[i] = aa;
		pq.emplace(aa, i); 
	}
	F0R(i, n-m-1) {
		auto [_, u] = *pq.begin();
		cout << u << "\n";
		pq.erase(pq.begin());
		int l = left[u], r = right[u];
		right[l] = r; left[r] = l;
		if (l) {
			pq.erase(pq.find({ar[l], l}));
			auto aa = area(a[left[l]], a[l], a[right[l]]);
			ar[l] = aa;
			pq.emplace(aa, l);
		}
		if (r != n-1) {
			pq.erase(pq.find({ar[r], r}));
			auto aa = area(a[left[r]], a[r], a[right[r]]);
			ar[r] = aa;
			pq.emplace(aa, r);
		}
	}

	return 0;
}
/*
0	[1]	2	3	4	5	6
0	2	3	4	5	6
*/