#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> iii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("firetrucksarered.in", "r", stdin);

	int n,i=0,m;
	cin>>n;
	vector<vi> al(n);
	vector<bool> vis(n, false);
	unordered_map<int,vi> la;

	for (int i = 0; i < n; ++i) {
		int k; cin>>k;
		while (k--) {
			int j; cin>>j;
			al[i].emplace_back(j);
			la[j].emplace_back(i);
		}
	}

	--n;
	stack<int> s;
	vector<iii> out;
	for (int i = 0; i <= n && out.size() < n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1; s.push(i);

		while (s.size() && out.size() < n) {
			int u = s.top(); s.pop();
			// cout << "visiting " << u << "\n";
			for (auto &j : al[u]) {
				for (auto &v : la[j]) {
					if (vis[v]) continue; // skips original i
					vis[v] = 1; s.push(v);
					out.emplace_back(u,v,j);
				}
				la[j].clear();
			}
		}
	}

	if (out.size() < n) { cout << "impossible"; return 0; }
	for (auto &[u,v,i] : out)
		cout << u+1 << " " << v+1 << " " << i << "\n";

	return 0;
}
