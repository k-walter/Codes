#include <bits/stdc++.h>
using namespace std;
// struct Trie {
// 	Trie* arr[26];
// 	bool end = 0;
// };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("phonelist.in", "r", stdin);

	int t,n,m; cin>>t;
	string line;
	while (t--) {
		cin>>n; cin.get();
		// Trie *t = new Trie(), *tt;
		string arr[n];
		for (int i = 0; i < n; ++i) getline(cin,arr[i]);
		sort(arr, arr+n);
		for (int i = 1; i < n; ++i) {
			m = min(arr[i].size(), arr[i-1].size());
			if (arr[i].substr(0, m) != arr[i-1].substr(0, m)) continue;
			cout << "NO\n";
			goto end;
		}
		// while (n--) {
		// 	getline(cin,line);
		// 	tt = t;
		// 	for (char &c:line) {
		// 		if (tt->end) { cout<<"NO\n"; goto end; }
		// 		if (tt->arr[c-'a'] == NULL) tt->arr[c-'a'] = new Trie();
		// 		tt = tt->arr[c-'a'];
		// 	}
		// 	tt->end = 1;
		// }
		cout<<"YES\n";
		end:;
	}

	return 0;
}