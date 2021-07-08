#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int s,p,m,n; 
int arr[1000000], nex[1000000];
ll dp[1000000];

inline ll val(int u) {
	if (u >= n) return 0;
	return dp[u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("busticket.in", "r", stdin);

	cin>>s>>p>>m>>n;
	int L=0;
	for (int i=0;i<n;++i) {
		cin>>arr[i];
		while (L<i and arr[L]+m<=arr[i])
			nex[L++] = i;
	}
	while (L<n) nex[L++]=n;
	for (int i=n-1;i>=0;--i)
		dp[i] = min(s+val(i+1), p+val(nex[i]));
	cout<<dp[0];

	return 0;
}
