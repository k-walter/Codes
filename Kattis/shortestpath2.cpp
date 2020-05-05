#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// using lli = pair<ll,int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using iiii = tuple<int,int,int,int>; // v,t0,P,d
using viiii = vector<iiii>;
const int INF = 1e9;

int n,m,q,s,u,v,t0,p,d;
vector<viiii> al;
vector<ll> dist;

int free(const int &t, const int &t0, const int &p) {
	// if P=0 cant use
	if (t <= t0) return t0; // t0 - t;
	if (p == 0) return INF;
	int i = (t - t0) % p;
	if (i == 0) return t;
	return t + p - i;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("shortestpath2.in", "r", stdin);

	while(cin>>n>>m>>q>>s, !(q==0 && m==0 && n==0 && s==0)) {
		al.clear(); al.resize(n);
		while (m--) {
			cin>>u>>v>>t0>>p>>d;
			al[u].emplace_back(v,t0,p,d);
		}

		dist.assign(n, INF); dist[s] = 0;
		priority_queue<ii, vii, greater<ii>> pq; pq.emplace(0,s);
		while (pq.size()) {
			auto [t,u] = pq.top(); pq.pop();
			if (t > dist[u]) continue;
			// cout << "visiting " << u << " at time " << t << "\n";
			for (auto &[v,t0,p,w] : al[u]) {
				if (free(t,t0,p)+w >= dist[v]) continue;
				dist[v] = free(t,t0,p)+w;
				pq.emplace(dist[v], v);
			}
		}

		while (q--) {
			cin>>v;
			if (dist[v] == INF) cout << "Impossible";
			else cout << dist[v];
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}