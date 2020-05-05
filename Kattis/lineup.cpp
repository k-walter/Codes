#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("lineup.in", "r", stdin);

	int n; cin >> n; cin.get();
	string prev; cin >> prev;

	--n;
	bool isAscend = true, isDescend = true;
	while (n-- && (isAscend || isDescend)) {
		string next; cin >> next;
		if (isAscend && (next <= prev)) {
			isAscend = false;
		} else if (isDescend && (next >= prev)) {
			isDescend = false;
		}
		prev = next;
	}

	if (isAscend) {
		cout << "INCREASING";
	} else if (isDescend) {
		cout << "DECREASING";
	} else {
		cout << "NEITHER";
	}

	return 0;
}