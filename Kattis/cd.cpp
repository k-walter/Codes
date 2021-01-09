#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("cd.in", "r", stdin);

	int a,b,in,i,ans;
	int arr[1000000];
	while(cin>>a>>b, (a!=0 || b!=0)) {
		for (i = 0; i < a; ++i) cin >> arr[i];
		i = ans = 0;
		while (b--) {
			cin >> in;
			if (i >= a || in < arr[i]) continue;
			while (i < a && in > arr[i]) ++i;
			if (in == arr[i]) ++ans;
		}
		cout << ans << "\n";
	}

	return 0;
}