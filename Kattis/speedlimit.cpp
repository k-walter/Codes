#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("speedlimit.in", "r", stdin);

	int n,ans,t,s,tp;
	while (scanf("%d",&n), n!=-1) {
		tp=ans=0;
		while (n--) {
			scanf("%d%d",&s,&t);
			ans+=(t-tp)*s;
			tp=t;
		}
		printf("%d miles\n", ans);
	}

	return 0;
}