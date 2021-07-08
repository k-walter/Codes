#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("primes.in", "r", stdin);

	ll arr[10],ar2[10],tmp[1024],lo,hi; int n;
	while (cin>>n,n) {
		for (int i=0;i<n;++i) {cin>>arr[i]; ar2[i]=arr[i]; }
			cin>>lo>>hi;
		set<int> s; s.insert(1);
		for (int i=0;i<n;++i) {
			for (int m=0; arr[i]<=hi; arr[i]*=ar2[i]) {
				vector<int> v;
				for (auto &u:s) {
					if (arr[i] * u > hi) break;
					v.push_back(arr[i] * u);
					tmp[m++]=arr[i] * u;
				}
				for (auto &j:v) s.insert(j);
				// while (m--) s.insert(tmp[m]);
			}
		}
		auto it = s.lower_bound(lo);
		if (it == s.end() or *it > hi) { cout<<"none\n"; continue; }
		cout<<(*it); ++it;
		for (;it!=s.end() and *it<=hi; ++it)
			cout<<','<<(*it);
		cout<<'\n';
	}

	return 0;
}