#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("simpleaddition.in", "r", stdin);

	string a,b; cin>>a>>b;
	int n=a.length()-1,m=b.length()-1;
	bool car = 0;
	vector<int> ans;
	int i = 0, sum;
	for (; i <= n && i <= m; ++i) {
		sum = (a[n-i]-'0') + (b[m-i]-'0') + car;
		car = sum / 10;
		ans.push_back(sum % 10);
	}
	for (; i <= n; ++i) {
		if (car && a[n-i]=='9') ans.push_back(0);
		else { ans.push_back((a[n-i]-'0')+car); car=0; }
	}
	for (; i <= m; ++i) {
		if (car && b[m-i]=='9') ans.push_back(0);
		else { ans.push_back((b[m-i]-'0')+car); car=0; }
	}
	if (car) ans.push_back(1);
	for (i = ans.size()-1; i >= 0; --i) cout << ans[i];
	return 0;
}