#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("ballotboxes.in", "r", stdin);

	int n, b, cur;
	ll l, r, m;
	vector<ll> no;
	while (cin>>n>>b, !(n==-1 && b==-1)) {
		l = r = 0;
		no.resize(n);
		for (ll &i : no) {
			cin >> i;
			r += i;
		}
		while (l < r) {
			m = (l + r) >> 1;
			cur = 0;
			// cout << "try " << m << " per box\n";
			for (ll &i : no) {
				const auto &[quo,rem] = div(i, m);
				cur += quo + (rem > 0);
				// cout << i << " people " << quo + (rem > 0) << " boxes " << cur << " cur\n";
				if (cur > b) break;
			}
			if (cur > b) l = m + 1;
			else r = m;
		}
		cout << l << "\n";
	}

	return 0;
}


/*

try 350000 per box
200000 people 1 boxes 1 cur
500000 people 2 boxes 3 cur
try 175000 per box
200000 people 2 boxes 5 cur
500000 people 3 boxes 8 cur
try 262500 per box
200000 people 1 boxes 9 cur
try 306250 per box
200000 people 1 boxes 10 cur
try 328125 per box
200000 people 1 boxes 11 cur
try 339063 per box
200000 people 1 boxes 12 cur
try 344532 per box
200000 people 1 boxes 13 cur
try 347266 per box
200000 people 1 boxes 14 cur
try 348633 per box
200000 people 1 boxes 15 cur
try 349317 per box
200000 people 1 boxes 16 cur
try 349659 per box
200000 people 1 boxes 17 cur
try 349830 per box
200000 people 1 boxes 18 cur
try 349915 per box
200000 people 1 boxes 19 cur
try 349958 per box
200000 people 1 boxes 20 cur
try 349979 per box
200000 people 1 boxes 21 cur
try 349990 per box
200000 people 1 boxes 22 cur
try 349995 per box
200000 people 1 boxes 23 cur
try 349998 per box
200000 people 1 boxes 24 cur
try 349999 per box
200000 people 1 boxes 25 cur
350000
try 3200 per box
120 people 1 boxes 1 cur
2680 people 1 boxes 2 cur
3400 people 2 boxes 4 cur
200 people 1 boxes 5 cur
try 1600 per box
120 people 1 boxes 6 cur
2680 people 2 boxes 8 cur
try 2400 per box
120 people 1 boxes 9 cur
try 2800 per box
120 people 1 boxes 10 cur
try 3000 per box
120 people 1 boxes 11 cur
try 3100 per box
120 people 1 boxes 12 cur
try 3150 per box
120 people 1 boxes 13 cur
try 3175 per box
120 people 1 boxes 14 cur
try 3188 per box
120 people 1 boxes 15 cur
try 3194 per box
120 people 1 boxes 16 cur
try 3197 per box
120 people 1 boxes 17 cur
try 3199 per box
120 people 1 boxes 18 cur
3200
[Finished in 3.6s]

*/