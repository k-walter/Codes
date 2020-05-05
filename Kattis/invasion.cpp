#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("invasion.in", "r", stdin);

	int n,m,a,k,u,v,w;
	vector<vii> al;
	vector<int> base, dist;
	priority_queue<ii, vii, greater<ii>> pq;
	while (cin>>n>>m>>a>>k, !(n==0 && m==0 && a==0 && k==0)) {
		al.assign(n, vii());
		while (m--) {
			cin>>u>>v>>w; --u; --v;
			al[u].emplace_back(v,w);
			al[v].emplace_back(u,w);
		}

		base.clear();
		while (a--) {
			cin>>u;
			base.emplace_back(u-1);
		}

		dist.assign(n, INF);
		for (auto &i : base) {
			if (n == 0) { cout << 0 << "\n"; continue; }
			// cout << "building " << i << "\n";
			if (dist[i] >= k) --n;
			dist[i] = 0; pq.emplace(0, i);
			while (pq.size()) {
				auto [d,u] = pq.top(); pq.pop();
				// cout << "visiting " << u << " distance " << d << "\n";
				if (d > dist[u]) continue;
				for (auto &[v,w] : al[u]) {
					if (d+w >= dist[v] || d+w >= k) continue;
					if (dist[v] >= k) --n;
					dist[v] = d+w;
					pq.emplace(d+w, v);
				}
			}
			cout << n << "\n";
		}
		cout << "\n";
		// return 0;
	}

	return 0;
}
