#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("pokerhand.in", "r", stdin);

	int hz[14] = {0}, ans=0;
	string s;
	for (int i = 0; i < 5; ++i) {
		cin>>s;
		switch(s[0]) {
			case 'A': ans=max(ans,++hz[1]); break;
			case 'T': ans=max(ans,++hz[10]); break;
			case 'J': ans=max(ans,++hz[11]); break;
			case 'Q': ans=max(ans,++hz[12]); break;
			case 'K': ans=max(ans,++hz[13]); break;
			default: ans=max(ans,++hz[s[0]-'0']); break;
		}
	}
	printf("%d\n", ans);

	return 0;
}