#include <bits/stdc++.h>
using namespace std;
int n;
string line;
set<tuple<int,int,int,int>> mem;
unordered_set<string> ans;
void dp(int i, int r, int c, int s, string a="") {
	if (r<0 || c<0 || s<0) return;
	if (i == n) {
		if (!(r||c||s)) ans.emplace(a);
		return;
	}
	switch (line[i]) {
		case '(': dp(i+1,r+1,c,s,a); return;
		case ')': dp(i+1,r-1,c,s,a); return;
		case '[': dp(i+1,r,c,s+1,a); return;
		case ']': dp(i+1,r,c,s-1,a); return;
		case '{': dp(i+1,r,c+1,s,a); return;
		case '}': dp(i+1,r,c-1,s,a); return;
	}
	if (mem.find({i,r,c,s}) != mem.end()) return;
	cout<<a<<"\n";
	mem.emplace(i,r,c,s);
	dp(i+1,r+1,c,s,a+"(");
	dp(i+1,r-1,c,s,a+")");
	dp(i+1,r,c,s+1,a+"[");
	dp(i+1,r,c,s-1,a+"]");
	dp(i+1,r,c+1,s,a+"{");
	dp(i+1,r,c-1,s,a+"}");
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("zapis.in", "r", stdin);

	cin>>n>>line;
	dp(0,0,0,0);
	printf("%d", ans.size());

	return 0;
}