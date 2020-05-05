#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using iis = tuple<int,int,string>;
priority_queue<iis> pq;
unordered_map<string,ii> um;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("doctorkattis.in", "r", stdin);

	int n,sev; cin>>n;
	string name;
	while (n--) {
		int q; cin>>q;
		switch (q) {
			case 0: // insert
				cin>>name>>sev;
				pq.emplace(sev, n, name);
				um[name] = {sev, n};
				break;
			case 1: { // increase
				cin>>name>>sev;
				auto &[sev2,nn] = um[name];
				sev2 += sev;
				pq.emplace(sev2, nn, name);
				break;
			}
			case 2: // remove
				cin>>name;
				um.erase(name);
				break;
			case 3: // top
				while (pq.size() && um.find(get<2>(pq.top())) == um.end())
					pq.pop();
				cout << (pq.empty() ? "The clinic is empty" : get<2>(pq.top())) << "\n";
				break;
		}
	}

	return 0;
}