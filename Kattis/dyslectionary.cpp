#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("dyslectionary.in", "r", stdin);

	string line;
	vector<string> v;
	while (getline(cin, line), !cin.eof()) {
		reverse(line.begin(), line.end());
		if (line != "") { v.emplace_back(line); continue; }

		sort(v.begin(), v.end());
		const int &size = (*max_element(v.begin(), v.end(), [](const string &a, const string &b) {
			return a.length() < b.length();
		})).length();
		for (auto &s : v) {
			reverse(s.begin(), s.end());
			for (int i = 0; i < size - s.size(); ++i) cout << " ";
			cout << s << "\n";
		}
		cout << "\n";
		v.clear();
	}

	sort(v.begin(), v.end());
	const int &size = (*max_element(v.begin(), v.end(), [](const string &a, const string &b) {
		return a.length() < b.length();
	})).length();
	for (auto &s : v) {
		reverse(s.begin(), s.end());
		for (int i = 0; i < size - s.size(); ++i) cout << " ";
		cout << s << "\n";
	}

	return 0;
}