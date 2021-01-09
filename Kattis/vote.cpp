#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("vote.in", "r", stdin);

	int tc; scanf("%d",&tc);
	int n,ans,hi,v,tot,j; bool win;
	while (tc--) {
		scanf("%d",&n);
		hi=-1;tot=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&v);
			tot+=v;
			if (v < hi) continue;
			if (v > hi) { win=1; j=i; hi=v; }
			else win=0;
		}
		if (!win) printf("no winner\n");
		else if ((hi<<1) > tot) printf("majority winner %d\n", j);
		else printf("minority winner %d\n", j);
	}

	return 0;
}