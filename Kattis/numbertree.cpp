#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("numbertree.in", "r", stdin);

	int n; string shift;
	cin >> n >> shift;

	int i = 1;
	for (auto &ch : shift) {
		i <<= 1;
		if (ch == 'R')
			i += 1;
	}

	cout << ((1 << ++n) - i);
	return 0;
}