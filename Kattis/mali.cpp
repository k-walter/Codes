#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("mali.in", "r", stdin);

	int n; cin >> n;
	int ahz[100]={0}, bhz[100]={0};
	int a, b, c, d, ans;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		++ahz[a-1]; ++bhz[b-1];
		// run through all pairs
		a=b=c=0; ans = 0;
		for (int j=-1,k=100; c < i;) {
			// while 0, get next A
			// while 0, get next B
			while (a == 0) a = ahz[++j];
			while (b == 0) b = bhz[--k];
			// save sum
			ans = max(ans, k+j+2);
			// subtract from both
			// subtract from leftover
			d = min(a, b);
			a-=d; b-=d; c+=d;
		}
		cout << ans << "\n";
	}

	return 0;
}

/*
1, 2, 3, 4
1, 7, 7, 8

1	1
2	1
3	1
4	1

1	1
7	2
8	1


*/