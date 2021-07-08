#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int f[] = {0,1,2,-1,-1,5,9,-1,8,6};
inline int flip(int u) {
	int v = 0;
	while (u) {
		int d = f[u % 10]; u /= 10;
		if (d == -1) return -1;
		v = v*10 + d;
	}
	return v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("addemup.in", "r", stdin);

	int n,s; scanf("%d%d",&n,&s);
	unordered_set<int> us(n<<1);
	while (n--) {
		int u; scanf("%d",&u);
		if (us.count(s-u)) { printf("YES"); return 0; }
		int v = flip(u);
		if (v != -1) {
			if (us.count(s-v)) { printf("YES"); return 0; }
			us.insert(v);
		}
		us.insert(u);
	}
	printf("NO"); 

	return 0;
}