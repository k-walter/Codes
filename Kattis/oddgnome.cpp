#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("oddgnome.in", "r", stdin);

	int n,m,i,ans,pre; scanf("%d",&n);
	while (n--) {
		scanf("%d%d",&m,&pre);
		for (int j = 2; j <= m; ++j) {
			scanf("%d",&i);
			if (++pre != i) { --pre; ans = j; }
		}
		printf("%d\n", ans);
	}

	return 0;
}