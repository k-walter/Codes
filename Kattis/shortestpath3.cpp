#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int,int,int> iii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("shortestpath3.in", "r", stdin);

	int n,m,q,s,u,v,w;
	while (cin>>n>>m>>q>>s, !(n==0 && m==0 && q==0 &&s==0)) {
		vector<iii> el;
		vector<vi> al(n);
		while (m--) {
			cin>>u>>v>>w;
			el.emplace_back(u,v,w);
			al[u].emplace_back(v);
		}
		random_shuffle(el.begin(), el.end());

		// bellman
		bool flag; bool fla[n];
		vector<int> dist(n, INF); dist[s] = 0;
		for (int i = 0; i < n; ++i) { // n rounds to check for -ve cycle
			flag = false; memset(fla, 0, sizeof(fla));
			// cout << "round " << i << "\n";
			for (auto &[u,v,w] : el) {
				if (dist[u] == INF || dist[u]+w>=dist[v]) continue;
				// cout << "relax " << u << " to " << v << " to " << dist[u]+w << "\n";
				dist[v] = dist[u] + w;
				flag = fla[v] = 1;
			}
			if (!flag) break; // no more relax
		}

		// -ve cycle
		stack<int> st;
		for (int i = 0; i < n; ++i) {
			if (!fla[i]) continue;
			st.push(i);
			while (st.size()) {
				u = st.top(); st.pop();
				for (auto &v : al[u]) {
					if (fla[v]) continue;
					fla[v] = 1; st.push(v);
				}
			}
		}

		while (q--) {
			// cout distance from s to node: -Infinity, Impossible, or x
			cin>>v;
			if (fla[v]) cout << "-Infinity";
			else if (dist[v] == INF) cout << "Impossible";
			else cout << dist[v];
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}