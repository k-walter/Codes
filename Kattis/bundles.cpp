#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

typedef bitset<100> bs;
typedef pair<int,bs> ib;
bs one;
int n,m;
map<ib,int> dp;
ib bd[150];

template<size_t s>
bool operator<(const bitset<s> &a, const bitset<s> &b) {
	for (int i = s-1; i >= 0; --i) {
		if (a[i] < b[i]) return 1;
	}
	return 0;
}

int f(int u=0, bs b=bs(), int cost=0) {
	if (b == one) return 0;
	if (u == n) return -1;
	ib it = {u,b};
	if (dp.count(it))
		return dp.find(it)->second;
	int &ans = dp[it];
	auto &[p,mask] = bd[u];
	ans = f(u+1, b, cost);
	bs bb = b | mask;
	if ((bb ^ b).any()) return ans;
	int tmp = f(u+1, bb, cost+p);
	if (tmp == -1) return ans;
	if (ans == -1) return ans = tmp;
	return ans = min(ans, tmp);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("bundles.in", "r", stdin);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		one.reset();
		for (int i=0;i<n;++i) one.set(i);
		cout<<one;
		for (int i=0;i<m;++i) {
			int k; auto &[p,b]=bd[i];
			cin>>p>>k; b.reset();
			while (k--) { int u; cin>>u; b.set(u-1); }
			cout << f() << "\n";
		}
	}

	return 0;
}