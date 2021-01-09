#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("thanosthehero.in", "r", stdin);

	int n; scanf("%d",&n);
	vector<int> arr(n);
	for (auto &i : arr) scanf("%d",&i);
	long long ans = 0;
	for (int i = n-1; i > 0; --i) {
		if (arr[i] > arr[i-1]) continue;
		ans += (arr[i-1] - arr[i] + 1);
		arr[i-1] = arr[i] - 1;
		if (arr[i-1] < 0) { ans = 1; break; }
	}
	printf("%ld\n", ans);

	return 0;
}