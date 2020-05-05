#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<pll>;
using ii = pair<int,int>;
using vii = vector<ii>;
/* original has same timing :( */
using id = pair<int,double>;
using vid = vector<id>;
using di = pair<double,int>;
using vdi = vector<di>;
const int MUL = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("getshorty.in", "r", stdin);

	int n,m;
	cout << fixed;
	while (cin>>n>>m, !(n==0 && m==0)) {
		vector<vii> al(n);
		while (m--) {
			int u,v; double w; cin>>u>>v>>w;
			al[u].emplace_back(v,w*MUL);
			al[v].emplace_back(u,w*MUL);
		}

		vector<double> dist(n, -1); dist[0] = MUL;
		priority_queue<ll, vll> pq; pq.emplace(MUL,0);
		--n;
		while (pq.size()) {
			auto [d,u] = pq.top(); pq.pop();
			if (d > dist[u]) continue;
			if (u == n) break;
			for (auto &[v,w] : al[u]) {
				if (d*w/MUL <= dist[v]) continue;
				dist[v] = d*w/MUL;
				pq.emplace(dist[v],v);
			}
		}

		cout << setprecision(4) << dist[n]/MUL << "\n";
	}

	return 0;
}