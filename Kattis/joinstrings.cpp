#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("joinstrings.in", "r", stdin);

	int n; cin >> n;
	list<string> strings[n]; // lists of string vs strings(n) = list of strings
	for (int i = 0; i < n; ++i) {
		string line; cin >> line;
		strings[i].push_back(line);
	}

	int to, from;
	for (int i = 1; i < n; ++i) { // n-1 rounds
		cin >> to >> from;
		strings[to-1].splice(strings[to-1].end(), strings[from-1]);
	}
	
	for (auto &ch: strings[to-1])
		cout << ch;
	cout << endl;

	return 0;
}