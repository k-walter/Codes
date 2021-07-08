#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("physicalmusic.in", "r", stdin);

	int t; scanf("%d",&t);
	while (t--) {
		int n; scanf("%d",&n);
		vi a(n); for (int &i:a) scanf("%d",&i);
		vi ans; int lo=n+1;
		for (int i=n;i;--i) {
			if (lo < a[i-1])  ans.push_back(a[i-1]);
			else lo = a[i-1];
		}
		sort(ans.begin(), ans.end());
		printf("%d\n",ans.size());
		for (int &j:ans) printf("%d\n", j);
	}
	/*
	doing better in single (compared to others) than dl
	*/


	return 0;
}