#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("askmarilyn.in", "r", stdin);

	for (int i = 0; i < 1000; ++i) {
        int d = rand() % 3;
        cout << (char)(d+'A') << "\n";
        string s; int e;
        cin>>s>>e;
        if (e) cout<<s<<"\n";
        else cout << (char)(3-d-(s[0]-'A')+'A') << "\n";
        cin>>e>>s;
    }

	return 0;
}