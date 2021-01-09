#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("memorymatch.in", "r", stdin);

	int n,k; cin>>n>>k;
	vector<string> arr(n); n = 0;
	int a,b; string s,t;
	unordered_map<string,int> um;
	while (k--) {
		cin>>a>>b>>s>>t;
		if (s == t) { arr[a-1]=arr[b-1]=""; n+=2; }
		else { arr[a-1]=s; arr[b-1]=t; }
	}
	sort(arr.begin(), arr.end());
	int unk = 0, ans = 0;
	while (n<arr.size() && arr[n]=="") { ++unk; ++n; }
	for (int i = n; i < arr.size(); ++i) if (arr[i] == arr[i-1]) ++ans;
	int known = arr.size() - n - (ans << 1);
	if (known >= unk) ans += (unk + known) >> 1;
	cout << ans;

	return 0;
}

/*
1 Earth
2 Mars
3 Sun [x]
4
5 Moon
6 Sun [x]
7 Earth
8

n = 3
n = 2

Remove remaining known pairs
If unknown == known, all
else if unknown == 2, all

A
A
B
x
x
*/