#include <bits/stdc++.h>
using namespace std;

int main2() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("baconeggsandspam.in", "r", stdin);

	int n;
	while (cin>>n, n) {
		cin.get();
		map<string,vector<string>> m;
		while (n--) {
			string line; getline(cin, line);
			size_t st = 0, en;
			char delim = ' ';
			
			en = line.find(' ', st);
			string name = line.substr(st,en-st);
			st = en + 1;

			while (en = line.find(' ', st), en != string::npos) {
				m[line.substr(st, en-st)].push_back(name);
				st = en + 1;
			}
			m[line.substr(st, en-st)].push_back(name);
		}

		for (auto &i : m) {
			cout << i.first;
			sort(i.second.begin(), i.second.end());
			for (auto &s : i.second)
				cout << " " << s;
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("baconeggsandspam.in", "r", stdin);

	int n;
	while (cin>>n, n) {
		cin.get();
		vector<pair<string,string>> v;
		while (n--) {
			string line; getline(cin, line);
			size_t st = 0, en;
			char delim = ' ';
			
			en = line.find(' ', st);
			string name = line.substr(st,en-st);
			st = en + 1;

			while (en = line.find(' ', st), en != string::npos) {
				v.emplace_back(line.substr(st, en-st), name);
				st = en + 1;
			}
			v.emplace_back(line.substr(st, en-st), name);
		}

		sort(v.begin(), v.end());
		string prev = v[0].first;
		cout << prev;
		for (auto &i : v) {
			if (i.first != prev) {
				prev = i.first;
				cout << "\n" << prev;
			}
			cout << " " << i.second;
		}
		cout << "\n\n";
	}

	return 0;
}