#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen(".in", "r", stdin);

	bool test = 1;
	int a = 10, b = 20;
	cout << (~test+1) << "\n";
	cout << ((test<<31)>>31) << "\n";
	cout << ((!test<<31)>>31) << "\n";
	cout << (((test<<31)>>31)&a) << "\n";
	cout << (((~test<<31)>>31)&b) << "\n";
	cout << ((test<<31>>31&a) | (~test<<31>>31&b));

	// (-(1&test) & 0) | (-(1&~test) & arr|mask)
	
	// am[out][u] = ((~val+1) & 0) | (~(~val+1) & (am[out][u]|mask));

	return 0;
}