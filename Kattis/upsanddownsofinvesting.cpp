#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("upsanddownsofinvesting.in", "r", stdin);

	int s,n,m; scanf("%d%d%d",&s,&n,&m);
	vi a(s); for (int &i:a) scanf("%d",&i);
	// peak
	vi b(s); b[0] = 1;
	for (int i=1;i<s;++i) {
		if (a[i] < a[i-1]) b[i] = 1;
		else b[i] = b[i-1] + 1;
	}
	int v = 1,ans=0;
	for (int i = s-2;i;--i) {
		if (a[i] < a[i+1]) v = 1;
		else ++v;
		if (a[i]<a[i+1] or a[i]<a[i-1]) continue;
		if (min(b[i], v) >= n) ++ans;
	}
	printf("%d ",ans);
	// valley
	// peak
	b[0] = 1;
	for (int i=1;i<s;++i) {
		if (a[i] > a[i-1]) b[i] = 1;
		else b[i] = b[i-1] + 1;
	}
	v = 1,ans=0;
	for (int i = s-2;i;--i) {
		if (a[i] > a[i+1]) v = 1;
		else ++v;
		if (a[i]>a[i+1] or a[i]>a[i-1]) continue;
		if (min(b[i], v) >= m) ++ans;
	}
	printf("%d",ans);
	//for (int &i:b) printf("%d ", i);

	return 0;
}