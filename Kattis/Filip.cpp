#include <bits/stdc++.h>
using namespace std;

int flip(int n) {
	return 100*(n%10) + 10*((n/10)%10) + (n/100);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("Filip.in", "r", stdin);

	int a,b; cin >> a >> b;
	cout << max(flip(a), flip(b));

	return 0;
}