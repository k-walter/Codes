#include <bits/stdc++.h>
using namespace std;

const int ST = 10000;
int m[2*ST+1];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("synchronizinglists.in", "r", stdin);

	while (cin>>n, n) {
		vector<int> orr(n), two(n);
		for (auto &i : orr) cin>>i;
		for (auto &i : two) cin>>i;

		vector<int> one(orr.begin(), orr.end());
		sort(one.begin(), one.end());
		sort(two.begin(), two.end());
		for (int i = 0; i < n; ++i) m[one[i]+ST] = two[i];

		for (auto &i : orr) cout << m[i+ST] << "\n";
		cout << "\n";
	}

	return 0;
}