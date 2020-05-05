#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print(priority_queue<ll, vector<ll>, greater<ll>> pq) {
	while (pq.size()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("canvas.in", "r", stdin);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vector<int> v(n);
		for (auto &i : v)
			cin >> i;

		priority_queue<ll, vector<ll>, greater<ll>> pq(v.begin(), v.end());
		// print(pq);
		ll total = 0;

		// when size=1, no need to paint!
		// but size>2, every run through uses paint regardless
		while (pq.size() >= 2) {
			ll top = pq.top(); pq.pop();
			top += pq.top(); pq.pop();
			pq.push(top); total += top;
			// cout<<total<<" | "; print(pq);
		}

		cout<<total<<"\n";
	}

	return 0;
}