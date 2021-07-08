#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("uprooted.in", "r", stdin);

	int V,E,s; cin>>V>>E>>s;
	// save min of permutations
	// sort by <min p, v>
	// bfs
		// for each edge
			// if seen
				// continue
			// add <bfs dist, u, v>
	// while not all V added
		// add lowest Vs

	return 0;
}