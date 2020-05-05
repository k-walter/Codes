#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> foo = {
	{'G', ' '},
	{'F', '-'},
	{'E', ' '},
	{'D', '-'},
	{'C', ' '},
	{'B', '-'},
	{'A', ' '},
	{'g', '-'},
	{'f', ' '},
	{'e', '-'},
	{'d', ' '},
	{'c', ' '},
	{'b', ' '},
	{'a', '-'},
};
string keys = "GFEDCBAgfedcba";

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("musicalnotation.in", "r", stdin);

	int n; cin >> n; cin.get();
	unordered_map<char,vector<char>> m;
	for (auto &c : keys) {
		vector<char> v;
		m.emplace(c, v);
	}

	while (n--) {
		string c; cin >> c;
		int tmp = 1;
		if (c.size() > 1)
			tmp = stoi(c.substr(1));
		while (tmp--)
			for (auto &d : keys)
				m[d].push_back((c[0] == d ? '*' : foo[d]));
		
		for (auto &d : keys)
			m[d].push_back(foo[d]);
	}
	for (auto &c : keys)
		m[c].pop_back();

	for (auto &c : keys) {
		cout << c << ": ";
		for (auto &d : m[c])
			cout << d;
		cout << "\n";
	}

	return 0;
}