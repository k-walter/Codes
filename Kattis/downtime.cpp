#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("downtime.in", "r", stdin);

	int n,k; scanf("%d%d",&n,&k);
	queue<int> q; int ans=1,svr=0,t;
	while (n--) {
		scanf("%d",&t);
		while (q.size() && q.front() <= t) { --svr; q.pop(); }
		ans = max(ans, ++svr);
		q.push(t+1000);
		// printf("%d %d\n", q.size(), svr);
	}
	printf("%d\n", ans/k + (ans%k != 0));

	return 0;
}