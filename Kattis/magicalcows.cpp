#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("magicalcows.in", "r", stdin);

	int c,n,m,i,j,k,hi=0; scanf("%d%d%d",&c,&n,&m);
	vector<int> init(n); for (int &i:init) scanf("%d",&i);
	vector<int> day(m); for (int &i:day) {
		scanf("%d",&i); hi=max(hi,i);
	}
	ll farm[hi+1][c+1]; memset(farm,0,sizeof farm);
	for (int &i:init) ++farm[0][i];
	// for (i=0;i<=c;++i) printf("%d\t", farm[0][i]); printf("\n");
	for (i=1;i<=hi;++i) {
		for (j=0;j<=c;++j) {
			if (farm[i-1][j] == 0) continue;
			// printf("day %d no %d hz %d\n", i,j,farm[i-1][j]);
			if ((j<<1) <= c) { farm[i][j<<1]+=farm[i-1][j]; continue; }
			farm[i][j] += farm[i-1][j] << 1;
		}
		// for (j=0;j<=c;++j) printf("%d\t", farm[i][j]); printf("\n");
	}
	ll tot;
	for (auto &d:day) {
		tot = 0;
		for (j=0;j<=c;++j) tot += farm[d][j];
		printf("%ld\n", tot);
	}

	return 0;
}
/*
d 0 1 2
0 0 3 2
1
*/