#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("combinationlock.in", "r", stdin);

	int a,b,c,d,ans;
	while(scanf("%d%d%d%d",&a,&b,&c,&d), a||b||c||d) {
		printf("%d\n", 9 * (80 + (a-b+40)%40 + 40 + (c-b+40)%40 + (c-d+40)%40));
	}

	return 0;
}