#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("closestsums.in", "r", stdin);

	int n,m,c=1,v,hi,lo,ans;
	int arr[1000];
	while(scanf("%d",&n) != EOF) {
		printf("Case %d:\n",c++);
		for (int i = 0; i < n; ++i) scanf("%d",&arr[i]);
		sort(arr, arr+n); // O(nlgn)
		scanf("%d",&m);
		while(m--) { // O(m)
			scanf("%d",&v);
			lo = 0; ans = 1e9;
			hi = lower_bound(arr,arr+n,v) - arr;
			if (hi >= n) hi = n-1;
			while (lo < hi) { // O(n)
				if (abs(arr[hi]+arr[lo]-v) < abs(ans-v)) ans=arr[hi]+arr[lo];
				if (arr[hi]+arr[lo] > v) --hi;
				else ++lo;
			}
			if (abs(arr[0]+arr[1]-v) < abs(ans-v)) ans=arr[0]+arr[1];
			printf("Closest sum to %d is %d.\n", v, ans);
		}
	}

	return 0;
}