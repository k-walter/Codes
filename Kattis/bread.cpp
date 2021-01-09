#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
	vector<bool> ft;
	FenwickTree(const int &n) { ft.assign(n+1, 0); }
	int rsq(int b) {
		bool sum = 0; for (; b; b&=(b-1)) sum ^= ft[b];
		return sum;
	}
	int rsq(int a, int b) {
		return rsq(b) ^ (a==1 ? 0 : rsq(a-1));
	}
	void add(int k, const bool &v) {
		for(; k<ft.size(); k+=(k&(-k))) ft[k] = ft[k] ^ v;
	}
};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("bread.in", "r", stdin);

	int n,u; scanf("%d",&n);
	vector<int> arr(n), ntoi(n+1);
	for (auto &i:arr) scanf("%d",&i);
	for (int i = 1; i <= n; ++i) { scanf("%d",&u); ntoi[u]=i; }
	for (auto &i:arr) i=ntoi[i];
	// Count even/odd #inversions
	FenwickTree ft(n);
	bool foo = 0;
	for (int &i:arr) {
		foo ^= ft.rsq(i+1, n);
		ft.add(i, 1);
	}
	printf(foo ? "Impossible" : "Possible");

	return 0;
}