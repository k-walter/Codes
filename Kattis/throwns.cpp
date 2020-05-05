#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("throwns.in", "r", stdin);

	int k, n; cin >> n >> k;
	deque<int> moves; // stack
	while (k--) {
		string i; cin >> i;
		if (i[0] != 'u') // move
			moves.push_back(stoi(i));
		else { // pop move
			int j; cin >> j;
			while (j-- && !moves.empty())
				moves.pop_back();
		}
	}

	int curr = 0;
	for (auto &i: moves)
		curr += i;
	curr %= n;
	if (curr < 0) curr += n;
	cout << curr;

	return 0;
}