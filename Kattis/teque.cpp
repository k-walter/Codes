#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("teque.in", "r", stdin);

	deque<int> left, right; // left.size() >= right.size()
	int n; cin >> n; cin.get();

	while (n--) {
		string cmd; cin >> cmd;
		int i; cin >> i;
		
		if (cmd[0] == 'g') { // get
			cout << (i >= left.size() ? right[i - left.size()] : left[i]) << "\n";
		}

		else {
			switch (cmd[5]) { // push_
				case 'b':
					right.push_back(i);
					if (right.size() > left.size()) {
						left.push_back(right.front());
						right.pop_front();
					}
					break;

				case 'f':
					left.push_front(i);
					if (left.size() - 1 > right.size()) {
						right.push_front(left.back());
						left.pop_back();
					}
					break;

				case 'm':
					if (left.size() > right.size())
						right.push_front(i);
					else
						left.push_back(i);
					break;
			}

			// for (auto j : left)
			// 	cout << j << " ";
			// for (auto j : right)
			// 	cout << j << " ";
			// cout << "\n";
		}
	}

	return 0;
}

int main2() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("teque.in", "r", stdin);

	deque<int> teque;
	// deque<int> left, right;
	int n; cin >> n; cin.get();

	// Since first input must be push
	// Avoids it is front() bug
	string cmd; cin >> cmd;
	int i; cin >> i;
	teque.push_back(i);

	auto it = teque.end();
	int med = 1;

	while (--n) {
		cin >> cmd;
		cin >> i;
		
		if (cmd[0] == 'g') { // get
			cout << teque[i] << "\n";
		}
		else {
			switch (cmd[5]) { // push_
				case 'b':
					teque.push_back(i);
					if (it == teque.end()) // if it at end
						it -= 1; // don't shift later
					break;
				case 'f':
					teque.push_front(i);
					med += 1; // compensate shifting right
					break;
				case 'm':
					teque.emplace(it, i);
					break;
			}

			int med_diff = (teque.size() + 1) / 2 - med;
			if (med_diff != 0) {
				it += med_diff;
				med += med_diff;
			}

			// for (auto j : teque)
			// 	cout << j << " ";
			// cout << "median " << *it << endl;
		}
	}

	return 0;
}