#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("compoundwords.in", "r", stdin);

	string word;
	vector<string> v; set<string> s;
	while(cin>>word, !cin.eof()) {
		for (auto &c : v) {
			s.emplace(word + c);
			s.emplace(c + word);
		}
		v.emplace_back(word);
	}

	for (auto &c : s)
		cout << c << "\n";

	return 0;
}