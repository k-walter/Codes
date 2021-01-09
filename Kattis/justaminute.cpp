#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("justaminute.in", "r", stdin);

	int n; scanf("%d",&n);
	int a,b,aa=0,bb=0;
	while (n--) {
		scanf("%d%d",&a,&b);
		aa+=a;bb+=b;
	}
	if (bb <= 60 * aa) printf("measurement error\n");
	else printf("%.17g\n", (double)bb/aa/60);

	return 0;
}