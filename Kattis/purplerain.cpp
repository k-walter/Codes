#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("purplerain.in", "r", stdin);

	string s; cin>>s;
	int L,R; L=R=0;
	for (int i=0,l=0,l2=0,v=0,v2=0,a=0;i<s.size();++i) {
		if (v<0) { l=i; v=0; }
		if (v2<0) { l2=i; v2=0; }
		v+=s[i]=='R'?1:-1;
		v2+=s[i]=='B'?1:-1;
		// cout<<v<<" "<<v2<<"\n";
		if (v>a) { a=v; L=l; R=i; }
		if (v2>a) { a=v2; L=l2; R=i; }
	}
	cout<<L+1<<" "<<R+1;

	return 0;
}

/*
B 	B 	R 	R 	B 	R 	R 	B 	R 	B
-1	-1	1	2	1	2	3	2	3	2

B 	B 	R 	B 	B 	R 	R 	B
-1	-1	1	0	-1	1	2	1
*/