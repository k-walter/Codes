#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s(2e6);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("cd.in", "r", stdin);

	int a,b;
	while(cin>>a>>b, (a!=0 || b!=0)) {
		s.clear();
		while (a--) {
			int i; cin>>i;
			s.insert(i);
		}

		int cnt = 0;
		while (b--) {
			int i; cin>>i;
			if (s.find(i) != s.end()) ++cnt;
		}

		cout << cnt << "\n";
	}

	return 0;
}