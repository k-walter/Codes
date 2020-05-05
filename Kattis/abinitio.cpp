#include <bits/stdc++.h>
using namespace std;

#define MAX 4000
#define FLIP(u,v) ((am[out][u].flip(v)), (am[out^1][v].flip(u)))

using bs = bitset<MAX>;
const int MOD = 1e9 + 7;

bs am[2][MAX]; // in,out
bs mask, mask2;
int u,v;
bool out = 0, val = 1;

// void flip(const int &u, const int &v) {
// 	am[out][u].flip(v); am[out^1][v].flip(u);
// 	// am[out][u][v] ^= 1; am[out^1][v][u] ^= 1;
// }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("abinitio.in", "r", stdin);

	int n,m,q; cin>>n>>m>>q;
	mask.set(); mask >>= (MAX-n);

	while (m--) {
		cin>>u>>v;
		FLIP(u,v);
	}

	while (q--) {
		int i; cin>>i; //cout << i << " ";
		switch (i) {
			case 1:
				if (val^1) {
					for (u = 0; u < n; ++u) {
						am[out][u].flip(n);
						am[out^1][u].flip(n);
						// FLIP(u,n); FLIP(n,u);
					}
					am[out^1][n] |= mask;
					am[out][n] |= mask;
				}
				++n; mask<<=1; mask.set(0);
				break;
			case 2:
			case 4:
				cin>>u>>v; FLIP(u,v); break;
			case 3:
				cin >> u; //cout << u;
				for (v = 0; v < n; ++v) {
					// if (u==v) continue;
					am[out^1][v][u] = am[out][v][u] = val^1;
					// if (am[out][u][v] == val) am[out^1][v].flip(u);
					// if (am[out][v][u] == val) am[out][v].flip(u);
				}
				am[out][u] = (val ? 0 : am[out][u]|mask);
				am[out^1][u] = (val ? 0 : am[out^1][u]|mask);
				// if (val) { // currently 1, reset to 0
				// 	am[out][u].reset(); am[out^1][u].reset();
				// } else { // currently 0, set to 1
				// 	am[out][u] |= mask; am[out^1][u] |= mask;
				// }
				break;
			case 5: out ^= 1; break;
			case 6: val ^= 1; break;
		}

		// for (int u = 0; u < n; ++u) {
		// 	cout << u << " | ";
		// 	for (int v = 0; v < n; ++v) {
		// 		cout << am[out][u][v];
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";
	}

	cout << n << "\n";
	for (u = 0; u < n; ++u) {
		auto &al = am[out][u];

		long long h = 0;
		int len = 0;
		for (v = n-1; v >= 0; --v) {
			if (al[v] ^ val || u == v) continue;
			h = (h * 7 + v) % MOD;
			++len;
		}
		cout << len << " " << h << "\n";
	}


	return 0;
}