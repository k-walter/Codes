#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("foregonesolutions.in", "r", stdin);

	int t; cin>>t;
	string n; queue<char> q; bool foo;
	for (int i = 1; i <= t; ++i) {
		cin>>n; foo = 0;
		for (auto &c : n) if (c=='4') { foo=1; break; }
		cout << "Case #" << i << ": "; 
		for (auto &c : n) {
			switch (c) {
				case '4': cout << 3; q.push('1'); break;
				case '0': cout << 0; if (!q.empty()) q.push('0'); break;
				case '5': if (!foo) { foo=1; cout<<3; q.push('2'); break; }
				default:
					if (!foo) { foo=1; cout<<c-1; q.push('1'); break; }
					cout << c; if (!q.empty()) q.push('0'); break;
			}
		}
		cout << " ";
		while (q.size()) { cout << q.front(); q.pop(); }
		cout << "\n";
	}

	return 0;
}