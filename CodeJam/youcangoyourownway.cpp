#include <bits/stdc++.h>
using namespace std;
#define MAX 50000
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("youcangoyourownway.in", "r", stdin);

	int t,n,y,x; cin>>t;
	char mv[MAX][MAX]; string in;
	for (int i = 1; i <= t; ++i) {
		cin>>n>>in; memset(mv,0,sizeof mv); y=x=0;
		cout << "Case #" << i << ": ";
		for (auto &c : in) { mv[y][x] = 1 + (c=='S'); c=='S' ? ++y : ++x; }
		y=x=0; --n;
		while (x!=n || y!=n) {
			if (x+1 > n || ) 
		}
	}

	return 0;
}