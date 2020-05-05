#include <bits/stdc++.h>
using namespace std;

int main4() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sim.in","r",stdin);

	clock_t st = clock();
	int n; cin >> n; cin.get();
	while (n--) {
		string line; getline(cin, line);
		list<char> out, aft;

		for (auto &ch : line) {
			switch (ch) {
				case '<':
					if (!out.empty())
						out.pop_back();
					break;
				case '[':
					aft.splice(aft.begin(), out);
					break;
				case ']':
					out.splice(out.end(), aft);
					break;
				default:
					out.push_back(ch);
			};
		}
		out.splice(out.end(), aft);

		for (auto &ch : out)
			cout << ch;
		cout << "\n";
	}

	cout << (float)(clock() - st)/CLOCKS_PER_SEC;
	return 0;
}

int main3() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sim.in","r",stdin);

	int n; cin >> n; cin.get();
	clock_t st = clock();
	while (n--) {
		string line; getline(cin, line);
		list<char> out;
		auto it = out.begin();

		for (auto &ch : line) {
			switch (ch) {
				case '<':
					if (it != out.begin())
						it = out.erase(--it); // delete prev
					break;
				case '[':
					it = out.begin();
					break;
				case ']':
					it = out.end();
					break;
				default:
					out.insert(it, ch); // insert before curr
			};
		}

		for (auto &ch : out)
			cout << ch;
		cout << "\n";
	}
	cout << (float)(clock() - st)/CLOCKS_PER_SEC;

	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sim.in", "r", stdin);

	clock_t st = clock();
	int n; cin >> n; cin.get();
	while (n--) {
		string line; getline(cin, line);
		deque<list<char>*> out = {new list<char>};
		list<char>* curr = out.front();

		for (auto &ch : line) {
			switch (ch) {
				case '<':
					if (!(curr->empty()))
						curr->pop_back();
					break;
				case '[':
					if (!(curr->empty())) {
						out.push_front(new list<char>);
						curr = out.front();
					}
					break;
				case ']':
					curr = out.back();
					break;
				default:
					curr->push_back(ch);
			};
		}
		
		for (auto &curr : out) {
			for (auto &ch : *curr) {
				cout << ch;
			}
		}
		cout << "\n";
	}

	cout << (float)(clock() - st)/CLOCKS_PER_SEC;
	return 0;
}