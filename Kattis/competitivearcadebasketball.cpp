#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("competitivearcadebasketball.in", "r", stdin);

	int n,p,m; cin>>n>>p>>m;
	unordered_map<string,int> s;
	while (n--) {
		string name; cin >> name;
		s.emplace(name, 0);
	}

	bool found = false;
	while (m--) {
		string name; int i;
		cin>>name>>i;
		auto it = s.find(name);
		if (it != s.end()) {
			it->second += i;
			if (it->second >= p) {
				cout << name << " wins!\n";
				s.erase(it);
				found = true;
			}	
		}
	}

	if (!found)
		cout << "No winner!";

	return 0;
}