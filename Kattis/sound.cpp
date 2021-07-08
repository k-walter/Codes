#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("sound.in", "r", stdin);

	int n,m,c; cin>>n>>m>>c;
	bool foo=1;
	deque<ii> lo,hi;
	for(int i=1;i<=n;++i) {
		int u; cin>>u;
		while (lo.size() and lo.back().first>=u) lo.pop_back();
		while (lo.size() and lo.front().second<i-m+1) lo.pop_front();
		lo.emplace_back(u,i);
		while (hi.size() and hi.back().first<=u) hi.pop_back();
		while (hi.size() and hi.front().second<i-m+1) hi.pop_front();
		hi.emplace_back(u,i);
		if (i<m) continue;
		if (hi.front().first - lo.front().first > c) continue;
		cout<<i-m+1<<"\n"; foo=0;
	}
	if (foo) cout<<"NONE";

	return 0;
}