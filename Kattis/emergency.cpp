#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("emergency.in", "r", stdin);

	long long n,k; cin>>n>>k; --n;
	cout << min(n, k + 1 + n%k); // since we might not need to jump

	return 0;
}