#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("canvasline.in", "r", stdin);

	int n; scanf("%d",&n);
	vii a(n); for (auto &[l,r]:a) scanf("%d%d",&l,&r);
	vi hz(n);
	scanf("%d",&n);
	vi b(n); for (auto &i:b) scanf("%d%d",&i);
	auto it = b.begin();
	for (int i = 0; i < a.size(); ++i) {
		int r; tie(ignore, r) = a[i];
		int &h = hz[i] = 0;
		while (*it < r) { ++h; ++it; }
	}
	for (int &i:hz) printf("%d ",i);

	return 0;
}
/*
5
2 15	1
15 25	0
25 40	1
42 52	1
52 62	1
3
5 29 52

3
0 60		2
60 120		3
120 140		1
4
20 60 80 120


2	15	15	25	25	40	42	52	52	62
  5  (15)    (25) 29    (42)  52    (62)
*/