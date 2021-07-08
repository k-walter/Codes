#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("score.in", "r", stdin);

	int n; scanf("%d\n",&n);
	int prv, a,b,at,bt;
	a=b=at=bt=prv=0;
	while (n--) {
		char c; int p; int h,m;
		scanf("%c %d %d:%d\n",&c,&p,&h,&m);
		m += h * 60;
		if (a > b) at += m - prv;
		else if (a < b) bt += m - prv;
		prv = m;
		if (c == 'A') a += p;
		else b += p;
	}
		if (a > b) at += 32 * 60 - prv;
		else if (a < b) bt += 32 * 60 - prv;
	printf("%c %d:%02d %d:%02d", a>b?'A':'H', bt/60, bt%60, at/60, at%60);

	return 0;
}