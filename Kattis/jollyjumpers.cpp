#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("jollyjumpers.in", "r", stdin);

	int n,a0,a1,ans;
	bool vis[3001], foo;
	while (scanf("%d",&n)!=EOF) {
		if (n == 0) {
			printf("Jolly\n");
			continue;
		}
		for (int i = 1; i < n; ++i) vis[i]=0;
		scanf("%d",&a0);
		foo=1;
		for (int i = 1; i < n; ++i) {
			scanf("%d",&a1);
			a0 = abs(a1-a0);
			if (a0>0 && a0<n && !vis[a0]) vis[a0]=1;
			else foo=0;
			a0 = a1;
		}
		printf(foo ? "Jolly\n" : "Not jolly\n");
	}

	return 0;
}