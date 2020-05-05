#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("Autori.in", "r", stdin);

	string line; cin >> line;
	for (auto ch: line) {
		if (isupper(ch))
			cout << ch;
	}
	cout << endl;

	return 0;
}