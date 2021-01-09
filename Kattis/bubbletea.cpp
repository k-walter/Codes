#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("bubbletea.in", "r", stdin);

	int n,m; scanf("%d",&n);
	// greedily select smallest
	vector<int> tea(n);
	for (auto &i : tea) scanf("%d",&i);
	scanf("%d",&m);
	vector<int> top(m);
	for (auto &i : top) scanf("%d",&i);
	int lo = INT_MAX,i;
	for (auto &t : tea) {
		scanf("%d",&m);
		while (m--) {
			scanf("%d",&i);
			lo = min(lo, t+top[i-1]);
		}
	}
	scanf("%d",&n);
	printf("%d\n", max(0, n/lo - 1));

	return 0;
}