#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("chopin.in", "r", stdin);

	string a,b; int i=1;
	while (!cin.eof(), cin>>a>>b) {
		cout<<"Case "<<i++<<": ";
		if (a.length() == 1) cout<<"UNIQUE";
		else if (a[1]=='#') cout<<(char)(a[0]+1 > 'G' ? 'A' : a[0]+1)<<"b "<<b;
		else cout<<(char)(a[0]-1 < 'A' ? 'G' : a[0]-1)<<"# "<<b;
		cout<<"\n";
	}

	return 0;
}