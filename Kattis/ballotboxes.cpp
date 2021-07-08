#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("ballotboxes.in", "r", stdin);

	int n, b;
	auto cmp = [](const ii &a, const ii &b) {
		// pop / box <= pop / box
		return a.first * b.second <= a.second * b.first;
	};
	while (cin>>n>>b, !(n==-1 && b==-1)) {
		if (n==1) { cout << b << "\n"; continue; }
		priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);
		b-=n; ll u;
		while (n--) { cin>>u; pq.emplace(u,1); }
		while (b) {
			auto [up,ub] = pq.top(); pq.pop();
			auto &[vp,vb] = pq.top();
			// ub? * vp > vb * up
			int L=ub+1, R=b,m;
			while (L<R) {
				m = (L + R) >> 1;
				if (m * vp > vb * up) R = m;
				else L = m + 1;
			}
			b -= L - ub;
			pq.emplace(up,L);
		}
		auto [p,v] = pq.top();
		cout << p/v + (p%v != 0) << "\n";
	}

	return 0;
}
