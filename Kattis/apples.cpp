#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("apples.in", "r", stdin);

	int n,m; scanf("%d%d",&n,&m);
	char g[n][m]; int a[m]={0};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf(" %c",&g[i][j]);
			switch (g[i][j]) {
				case 'a': ++a[j]; g[i][j]='.'; break;
				case '#':
					for (int k = i-1; a[j]; --a[j], --k) g[k][j]='a';
					break;
			}
		}
	for (int j = 0; j < m; ++j)
		for (int k = n-1; a[j]; --a[j], --k)
			g[k][j]='a';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) printf("%c", g[i][j]);
		printf("\n");
	}

	return 0;
}