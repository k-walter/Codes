#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<vi> al;
vector<bool> lab(100000);

int topo(bool f, vi in, deque<int> q) {
	int no = 0;

	while (q.size()) {
		int u = (f ? q.front() : q.back());
		if (lab[u] != f) {
			++no;
			f = !f;
			u = (f ? q.front() : q.back());
		}
		f ? q.pop_front() : q.pop_back();
		for (int &v : al[u]) {
			if (--in[v] != 0) continue;
			lab[v] ? q.push_front(v) : q.push_back(v);
		}
	}

	return no;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("conservation.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) {
		int n,m; cin>>n>>m;
		al.clear(); al.resize(n);
		vi in(n,0);
		
		for (int i = 0; i < n; ++i) {
		 	int j; cin>>j;
		 	lab[i] = (j==1 ? 1 : 0);
		}

		while (m--) {
			int u,v; cin>>u>>v;
			--u; --v;
			al[u].push_back(v);
			++in[v];
		}

		deque<int> q;
		for (int i = 0; i < n; ++i) {
			if (in[i] != 0) continue;
			lab[i] ? q.push_front(i) : q.push_back(i);
		}

		if (lab[q.front()] == lab[q.back()]) cout << topo(lab[q.front()],in,q);
		else cout << min(topo(true,in,q), topo(false,in,q));
		cout << "\n";
	}

	return 0;
}