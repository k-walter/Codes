#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int lo=1,hi=1000,m;
	string line;
	while (lo < hi) {
		m = (lo+hi)>>1;
		cout << m << endl;
		getline(cin,line);
		switch (line[0]) {
			case 'l': hi=m-1; break;
			case 'h': lo=m+1; break;
			case 'c': return 0;
		}
	}
	cout<<lo;

	return 0;
}