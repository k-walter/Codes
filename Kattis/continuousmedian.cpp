#include <bits/stdc++.h>
using namespace std;

void print_queue(priority_queue<unsigned int> old) {
	if (old.empty()) {
		return;
	}

	int top = old.top();
	old.pop(); // doesn't affect original
	print_queue(old); // recursion to print last first
	cout << top << " ";
}

void print_queue2(priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> old) {
	while(!old.empty()) {
		cout << old.top() << " ";
		old.pop();
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("continuousmedian.in", "r", stdin);

	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		priority_queue<unsigned int> left;
		priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> right; // min at top

		unsigned long long int total = 0;
		for (int i = 1; i <= k; ++i) { // no of items
			int tmp; cin >> tmp;

			// Odd: Add Left
			if (i % 2) {
				if (left.empty() || tmp <= right.top()) {
					left.push(tmp);
				} else {
					left.push(right.top());
					right.pop();
					right.push(tmp);
				}

				total += left.top();
			}

			// Even: Add right
			else {
				if (tmp >= left.top()) {
					right.push(tmp);
				} else {
					right.push(left.top());
					left.pop();
					left.push(tmp);
				}

				total += (left.top() + right.top()) / 2;
			}

			print_queue(left); cout << endl;
			print_queue2(right);
			cout << "Total: " << total << "\n\n";
		}
		cout << total << endl;
	}

	return 0;
}