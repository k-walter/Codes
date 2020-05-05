#include <bits/stdc++.h>
using namespace std;

int x; 
vector<int> length;
bool dfs(int l, vector<unordered_set<int>> &al, vector<bool> &left) {
	if (l == x)
		return true;

	// cout << l << "\n";
	left[l] = true;
	for (auto &i : al[l]) {
		if (!left[i]) {
			al[i].erase(l);
			if (al[i].size() * 2 <= length[i])
				if (dfs(i, al, left)) {
					// cout << i << " "<< al[i].size() << "\n";
					return true;
				}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("brexit.in", "r", stdin);

	int c,p,l; cin>>c>>p>>x>>l;
	if (x==l) {
		cout << "leave";
		return 0;
	}
	--x; --l;

	vector<unordered_set<int>> al(c);
	while (p--) {
		int a,b; cin>>a>>b;
		al[a-1].insert(b-1);
		al[b-1].insert(a-1);
	}
	for (auto &s : al)
		length.push_back(s.size());

	vector<bool> left(c, false);
	cout << (dfs(l, al, left) ? "leave" : "stay");
	return 0;
}