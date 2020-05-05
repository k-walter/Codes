#include <bits/stdc++.h>
using namespace std;

map<char, char> villain = {
	{ 't', '|' },
	{ 'j', '*' },
	{ 'b', '$' },
};
bool valid(stack<char>& backpack, char ch) {
	switch (ch) {
		case '.': break; // ground
		case 't':
		case 'j':
		case 'b':
			if (backpack.empty() || backpack.top() != villain[ch])
				return false;
			backpack.pop();
			break;
		default:
			backpack.push(ch);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("thegrandadventure.in", "r", stdin);

	int n; cin >> n; cin.get();
	while (n--) {
		stack<char> backpack;
		string line; cin >> line;

		bool isvalid = true;
		for (char ch : line) {
			if (!valid(backpack, ch)) {
				isvalid = false;
				break;
			}
		}
		cout << ((isvalid && backpack.empty()) ? "YES" : "NO") << endl;
	}

	return 0;
}
