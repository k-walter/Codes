#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("divideby100.in", "r", stdin);

	string a,b; cin>>a>>b;
	// strip 0
	int i = 0, n = a.length()-1, m = b.length()-1;
	while (i<=n && i<=m && a[n-i]==b[m-i]) ++i;
	a=a.substr(0,n-i+1); b=b.substr(0,m-i+1);
	// print
	n=a.length(); m=b.length()-1;
	if (n > m) {
		cout << a.substr(0, n-m);
		if (m) cout << '.' << a.substr(n-m);
	} else {
		cout << "0.";
		for (int i = 0; i < m-n; ++i) cout << "0";
		cout << a;
	}

	return 0;
}