#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int n,r,o; 
inline int idle(int u) {
	if (u >= n) return 0;
	int ans = (n - u);
	return ans + (ans & 1);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("climbingstairs.in", "r", stdin);

	scanf("%d%d%d",&n,&r,&o);
	int ans = max(r,o);
	if (r < o) ans += o - r;
	ans += idle(ans) + r;
	printf("%d", ans);
	// max(register, office)
	// register > office
		// idle
		// ground
	// register < office
		// back to register
		// idle
		// ground


	return 0;
}
