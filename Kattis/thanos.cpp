#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("thanos.in", "r", stdin);

	int t, ans;
	long long p,r,f; scanf("%d",&t);
	while (t--) {
		scanf("%lld%lld%lld",&p,&r,&f);
		ans = 0;
		while (p <= f) {
			p *= r; ++ans;
		}
		printf("%lld\n", ans);
	}

	return 0;
}