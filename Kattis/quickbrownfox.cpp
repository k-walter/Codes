#include <cstdio>
#include <cstring>
int main_cstdio() {
	freopen("quickbrownfox.in", "r", stdin);

	int n; scanf("%d", &n);
	char arr[100];
	while (n--) {
		// string line; getline(scanf, line);
		printf("%s\n", arr);
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

class pangram {
private:
	vector<bool> char_exists;

public:
	pangram(string line) { // consturctor
		char_exists.assign(26, false);
		for (int i = 0; i < line.length(); ++i) {
			char ch = tolower(line[i]);
			// if (!isalpha(ch)) continue; // not ['a',...,'z']
			if (isalpha(ch)) {
				char_exists[ch - 'a'] = true;
			}
		}
	}

	bool is_pangram() {
		bool ispangram = true;
		for (int i = 0; i < 26; ++i) {
			// ispangram &= !char_exists[i]; // ispangram & !char_exists
			if (!char_exists[i]) {
				ispangram = false;
				break;
			}
		}
		return ispangram;
	}

	bool is_exists(char ch) {
		return char_exists[ch - 'a'];
	}

}; // ; necessary

int main() {
	// main_cstdio();
	// return 0;

	ios::sync_with_stdio(false); cin.tie(NULL); // iostream
	freopen("quickbrownfox.in", "r", stdin);

	int n; cin >> n; cin.get(); // consume \n
	while (n--) {
		string line; getline(cin, line);
		vector<bool> char_exists(26, false); // c++ of below
		// bool char_exists[26];
		// for (int i = 0; i < 26; ++i) {
		// 	char_exists[i] = false;
		// }

		for (int i = 0; i < line.length(); ++i) {
			char ch = tolower(line[i]);
			// if (!isalpha(ch)) continue; // not ['a',...,'z']
			if (isalpha(ch)) {
				char_exists[ch - 'a'] = true;
			}
		}

		bool ispangram = true;
		for (int i = 0; i < 26; ++i) {
			// ispangram &= !char_exists[i]; // ispangram & !char_exists
			if (!char_exists[i]) {
				if (ispangram)
					cout << "missing ";
				ispangram = false;
				cout << (char)(i + 'a');
			}
		}
		if (ispangram)
			cout << "pangram";
		cout << endl;
	}
	return 0;
}