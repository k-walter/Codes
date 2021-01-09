#include <bits/stdc++.h>
using namespace std;
typedef double db;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("rainfall2.in", "r", stdin);

	db L,K,T1,T2,H; scanf("%lf%lf%lf%lf%lf",&L,&K,&T1,&T2,&H);
	if (H < L) {
		printf("%lf %lf\n", H,H);
	} else {
		db lo = H / T1, hi = 1e8, m, h;
		do {
			m = (hi + lo) / 2;
			h = T1 * m - (T1 + T2 - L / m) * K;
			if (H > h) lo = m;
			else hi = m;
		} while (abs(H-h) >= 1e-7);
		m *= T1;
		printf("%lf %lf\n", (H > L) ? m : L, m);
	}

	return 0;
}