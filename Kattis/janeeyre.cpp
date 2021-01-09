#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,ll> si;
typedef vector<si> vsi;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("janeeyre.in", "r", stdin);

	ll n,m,k; cin>>n>>m>>k; cin.get();
	string line, delim="\"";
	vsi cur(n); for (auto &[s,i]:cur) {
		getline(cin, line);
		int start = line.find(delim) + delim.size(), end = line.find(delim, start);
		s = line.substr(start,end-start);
		start = end + delim.size(); end = line.find(delim, start);
		i = stoi(line.substr(start,end-start));
	}
	cur.reserve(n+m+1); cur.emplace_back("Jane Eyre", k);
	vector<tuple<ll,string,ll>> in(m);
	for (auto &[t,s,i]:in) {

		getline(cin, line);
		int start = 0, end = line.find(delim, start);
		// cout << line.substr(start, end-start) << "\n"; return 0;
		t = stoi(line.substr(start,end-start));
		start = end + delim.size(); end = line.find(delim, start);
		s = line.substr(start,end-start);
		start = end + delim.size(); end = line.find(delim, start);
		i = stoi(line.substr(start,end-start));
	}
	sort(in.begin(), in.end());
	priority_queue<si, vsi, greater<si>> pq(cur.begin(), cur.end());
	ll t=0,r=0;
	while (1) {
		while (r<in.size() && get<0>(in[r]) <= t) {
			auto &[t,s,i]=in[r];
			pq.emplace(s,i); ++r;
			// cout<<"adding "<<s<<"\n";
		}
		auto [s,i] = pq.top(); pq.pop();
		t += i;
		// cout<<"reading "<<s<<" time " << t<<"\n";
		if (s == "Jane Eyre") { cout<<t; return 0; }
	}

	return 0;
}