#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("johnsstack.in", "r", stdin);



	return 0;
}
/*
T(0)

[] = 0
[3] = 0
[1 3] = 1
[1 3 4] = 1 + 0
[1 1 3 4] = 1 + 1 = 2
[1 1 3 4 5 9] = 2 + 0
[1 1 2 3 4 5 9] = 2 + [1 1]
[1 1]

3 1 4 1 5 9 2 6

1 1 3 4 5 9

1. doesn't matter what the numbers are, but the relative order

1
ans = 0

2 1
1 2
ans = 1

1 1
ans = 0

3 1 2 [3 4 5 ...] [3]
1 3 2
2 1 3
ans = 2 + 1

3 2 1
2 3 1
1 2 3
ans = 2

2 1 1
1 2 1
1 1 2
ans = 2



1 3 4
1 1 3 4 5 9
2 1 1 3 4 5 9
1 2
1 1 2 3 4 5 9
6
1 6
1 1 6
2
1 2
1 1 2 6
3
1 3
1 1 3
2
1 2
1 1 2 3 6

1 1 2 6
1 1 2 3 6
1 1 2 3 4 6
1 1 2 3 4 5 6 9
*/