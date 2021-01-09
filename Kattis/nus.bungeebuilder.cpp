#include <bits/stdc++.h>
using namespace std;
int h[1000000], rtl[1000000];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.bungeebuilder.in", "r", stdin);

	int n; scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",&h[i]);
	rtl[n-1] = h[n-1];
	for (int i = n-2; i > 1; --i)
		rtl[i] = max(h[i], rtl[i+1]);
	int ans = 0, L=h[0];
	for (int i = 1; i < n-1; ++i) {
		ans = max(ans, min(L,rtl[i+1]) - h[i]);
		L = max(L, h[i]);
	}
	printf("%d\n", ans);

	return 0;
}