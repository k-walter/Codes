#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("ceremony.in", "r", stdin);

	int n; cin>>n;
	vi a(n); for (int &i: a) cin>>i;
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = min(min(ans+1, i), a[i-1]);
	}
	cout << ans;

	return 0;
}