#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("caching.in", "r", stdin);

	int c,n,a; cin>>c>>n>>a;
	unordered_map<int,stack<int>> next(n<<1);
	unordered_set<int> vis(c<<1);
	vector<int> qry(a);
	for (int &i : qry) cin >> i;
	for (int i = a-1; i >= 0; --i) next[qry[i]].push(i);
	int ans = 0;
	priority_queue<ii> cache;
	for (int &i : qry) {
		// skip if in cache
		if (vis.find(i) != vis.end()) {
			int &cur = next[i].top();
			next[i].pop();
			int &nex = next[i].size() ? next[i].top() : a;
			cache.emplace(nex, i);
			continue;
		}
		// pop latest from cache
		if (vis.size() == c) {
			while (1) {
				auto &[pos,no] = cache.top();
				auto &st = next[no];
				if (st.empty()) if (pos==a) break;
				if (st.top() == pos) break;
				cache.pop();
				// return 0;
			}
			auto &[pos,no] = cache.top();
			vis.erase(no);
			cache.pop();
		}
		vis.insert(i);
		++ans;
		// add to cache
		next[i].pop();
		int &nex = next[i].size() ? next[i].top() : a;
		cache.emplace(nex, i);
		// cout << i << " | ";
		// for (auto &b : vis) cout << b << " ";
		// cout << " | " << ans << "\n";
	}
	cout << ans;

	return 0;
}