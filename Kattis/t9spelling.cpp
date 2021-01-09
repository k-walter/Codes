#include <bits/stdc++.h>
using namespace std;
int um[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int hz[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("t9spelling.in", "r", stdin);


	int t; cin>>t; cin.get();
	string line;
	int j, k, pre;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		getline(cin,line);
		pre=0;
		for (auto &c : line) {
			j = (c == ' ') ? 0 : um[c-'a'];
			k = (c == ' ') ? 1 : hz[c-'a'];
			if (pre == j) cout << " ";
			while (k--) cout << j;
			pre = j;
		}
		cout << "\n";
	}

	return 0;
}