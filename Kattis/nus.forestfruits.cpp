#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> path;
bool fr[20000] = {0};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("nus.forestfruits.in", "r", stdin);

	// C clearings, K regrow, M days
	int V,E,C,K,M,u,v,w; scanf("%d%d%d%d%d",&V,&E,&C,&K,&M);
	// Determine if M days can collect
	if (C < min(K,M)) { printf("-1\n"); return 0; }
	// Input
	vector<vector<pair<int,int>>> al(V);
	while (E--) {
		scanf("%d%d%d",&u,&v,&w);
		al[u-1].emplace_back(v-1,w);
		al[v-1].emplace_back(u-1,w);
	}
	while (C--) {
		scanf("%d",&u);
		fr[u-1] = 1;
	}
	C = min(K,M);
	// Determine SSSP to all fruits
	vector<ll> dist(V, 1e18);
	priority_queue<path,vector<path>,greater<path>> pq;
	pq.emplace(0,0); dist[0]=0;
	while (pq.size()) {
		auto [d,u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		if (fr[u] && (--C)==0) { // furthest fruit within constraint
			printf("%lld\n", d<<1);
			return 0;
		}
		for (auto &[v,w] : al[u]) {
			if (d+w >= dist[v]) continue;
			dist[v]=d+w; pq.emplace(dist[v],v);
		}
	}
	printf("-1\n"); // unreachable

	return 0;
}