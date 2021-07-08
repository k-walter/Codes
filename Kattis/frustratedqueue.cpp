#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int dp[1000][501], vis[1000][501], cur=0;
string line;
int f(int u, int sum, int on=0, int off=0) {
	if (sum < 0 or (on<<1)>line.size() or (off<<1)>line.size()) return 0;
	if (u == line.size()) return 1;
	if (line[u] != '.') {
		if (line[u]=='(') return f(u+1, sum+1, on+1, off);
		return f(u+1, sum-1, on, off+1);
	}
	if (vis[u][sum] == cur) return dp[u][sum];
	vis[u][sum] = cur;
	int &ans = dp[u][sum];
	ans = f(u+1, sum+1, on+1, off);
	ans += f(u+1, sum-1, on, off+1);
	ans %= 1000000;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("frustratedqueue.in", "r", stdin);

	memset(vis, 0, sizeof vis);
	while (getline(cin, line)) {
		++cur;
		cout<<f(0,0)<<"\n";
	}

	return 0;
}