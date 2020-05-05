#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("invasion.in", "r", stdin);

	int n,m,a,k,u,v,w,d;
	vector<vii> al;
	vector<int> base, dist;
	deque<int> q; int tot = 0; vector<bool> in;
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

		dist.assign(n, INF); in.assign(n, 0);
		for (auto &i : base) {
			if (n == 0) { cout << 0 << "\n"; continue; }
			// cout << "building " << i << "\n";
			if (dist[i] >= k) --n;
			dist[i] = 0; q.emplace_front(i);
			while (pq.size()) {
				u = pq.front(); pq.pop_front();
				in[u] = 0;
				// cout << "visiting " << u << " distance " << d << "\n";
				for (auto &[v,w] : al[u]) {
					if (dist[u]+w >= dist[v] || dist[u]+w >= k) continue;
					if (dist[v] >= k) --n;
					dist[v] = dist[u]+w;

					if (in[v]) continue;
					in[v] = 1;
					(dist[v] < q.front().first) ? q.emplace_front(dist[v], v) : q.emplace_back(dist[v], v);
					
					// tot += d+w; int avg = tot / q.size();
					// if 
				}
			}
			cout << n << "\n";
		}
		cout << "\n";
		// return 0;
	}

	return 0;
}
