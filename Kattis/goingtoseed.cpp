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
	// freopen("goingtoseed.in", "r", stdin);

	int n; scanf("%d",&n);
	int L=1, R=n;
	while (L < R) {

		// dist 2
		if (L+1 == R) {
			printf("Q %d %d %d %d\n", L, L, R, R);
			int w1,w2; scanf("%d%d", &w1, &w2);
			printf("A ");
			if (w1) printf("%d", L);
			else if (w2) printf("%d", R);
			fflush(stdout);
			return 0;
		}

		// dist 3
		if (L+2 == R) {
			int L2 = L+1;
			printf("Q %d %d %d %d\n", L, L, L2, L2);
			int w1,w2; scanf("%d%d", &w1, &w2);
			printf("A ");
			if (w1) printf("%d", L);
			else if (w2) printf("%d", L2);
			else printf("%d", R);
			fflush(stdout);
			return 0;
		}

		// dist 4
		if (L+3 == R) {
			int L2 = L+1, R2=L+2;
			printf("Q %d %d %d %d\n", L, L2, L2, R2);
			int w1,w2; scanf("%d%d", &w1, &w2);
			printf("A ");
			if (w1 and w2) printf("%d", L2);
			else if (w1) printf("%d", L);
			else if (w2) printf("%d", R2);
			else printf("%d", R);
			fflush(stdout);
			return 0;
		}

		// ternary search
		int d = ceil((double)(R-L+1)/3);
		int L2 = min(R, L + d);
		int L3 = min(R, L2 + d);
		int R1 = L2-1;
		int R2 = max(L3-1,L2);
		if (L+3 == R) --L2;
		printf("Q %d %d %d %d\n", L, R1, L2, R2);
		fflush(stdout);
		int w1,w2; scanf("%d%d", &w1, &w2);

		if (L+3 >= R) {
			printf("A ");
			if (w1 and w2) printf("%d", L2);
			else if (w1) printf("%d", L);
			else if (w2) printf("%d", R2);
			else printf("%d", L3);
			fflush(stdout);
			return 0;
		}

		if (w1) { L=max(1,L-1); R=min(n,R1+1); }
		else if (w2) { L=max(1,L2-1); R=min(n,R2+1); }
		else { L=max(1,L3-1); R=min(n,R+1); }
		// printf("L %d R %d\n", L, R);
	}

	return 0;
}