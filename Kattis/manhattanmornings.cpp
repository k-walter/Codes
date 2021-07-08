#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("manhattanmornings.in", "r", stdin);

	int n; cin>>n;
	int sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;
	int dy=1,dx=1;
	if (tx<sx) { swap(tx,sx); dx=-1; }
	if (ty<sy) { swap(ty,sy); dy=-1; }
	vii q;
	while (n--) {
		int x,y; cin>>x>>y;
		if (x<sx or x>tx or y<sy or y>ty) continue;
		q.emplace_back(dy*y, dx*x);
	}
	sort(q.begin(), q.end());
	vi ans;
	for (auto &[y,x]:q) {
		if (ans.empty() or x >= ans.back()) { ans.push_back(x); continue; }
		auto it = upper_bound(ans.begin(), ans.end(), x);
		*it = x;
		// for (auto &x:ans) cout<<x<<" "; cout<<"\n";
	}
	cout<<ans.size();

	return 0;
}