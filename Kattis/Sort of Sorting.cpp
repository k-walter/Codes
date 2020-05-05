#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("Sort of Sorting.in", "r", stdin);

	int n;
	while(cin >> n, n) {
		// cin.get();

		vector<string> names(n);
		for (auto &name : names)
			cin >> name;

		// index
		// vector<size_t> idx(names.size());
		// iota(idx.begin(), idx.end(), 0);
		// vector<string> names_2(names.size());

		stable_sort(names.begin(), names.end(),
			[](string a, string b) { // lambda
				// splices(st, no of items)
				return a.substr(0,2) < b.substr(0,2);
				// OR
				// return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[1];
			});

		for (auto &name : names) {
			cout << name << endl;
		}
		cout << endl;
	}

	return 0;
}