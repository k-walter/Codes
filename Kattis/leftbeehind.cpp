#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("leftbeehind.in", "r", stdin);

	int x,y;
	while (scanf("%d%d",&x,&y), x||y) {
		if (x+y == 13) printf("Never speak again.\n");
		else if (x<y) printf("Left beehind.\n");
		else if (x>y) printf("To the convention.\n");
		else printf("Undecided.\n");
	}


	return 0;
}