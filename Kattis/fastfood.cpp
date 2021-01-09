#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("fastfood.in", "r", stdin);

	int tc; scanf("%d",&tc);
	int n,m,k,ans,lo;
	int prz[10][31], val[10], stk[31];
	while (tc--) {
		scanf("%d%d",&n,&m);
		memset(prz,0,sizeof prz);
		for (int j = 0; j < n; ++j) {
			scanf("%d",&prz[j][0]);
			for (int i = 1; i <= prz[j][0]; ++i)
				scanf("%d",&prz[j][i]);
			scanf("%d",&val[j]);
		}
		for (int i = 1; i <= m; ++i)
			scanf("%d",&stk[i]);
		ans=0;
		while (n--) {
			lo=INT_MAX;
			for (int i = 1; i <= prz[n][0]; ++i)
				lo = min(lo, stk[prz[n][i]]);
			ans += val[n] * lo;
		}
		printf("%d\n", ans);
	}

	return 0;
}