#include <bits/stdc++.h>
using namespace std;

using vii = vector<pair<int,int>>;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("traveltheskies.in", "r", stdin);

	int k,n,m; cin>>k>>n>>m;

	// flights
	vector<vector<vii>> fly(n, vector<vii>(k)); // day, airport1, passengers, airport2
	while (m--) {
		int u,v,d,z; cin>>u>>v>>d>>z;
		fly[d-1][u-1].emplace_back(z, v-1); // can fly to >1 airport!!!
	}
	// for (auto &i : fly) { // day
	// 	for (auto &k : i) { // airport
	// 		for (auto &j : k) // flight
	// 			cout << j.first << " " << j.second;
	// 		cout << ", ";
	// 	}
	// 	cout << "\n";
	// }

	// new arrivals
	vector<vector<int>> pp(n, vector<int>(k)); // day, airport : no people at each airport at the end of the day
	for (int i = 0; i < k*n; ++i) {
		int a,d,c; cin>>a>>d>>c;
		pp[d-1][a-1] = c;
	}
	// for (auto &i : pp) {
	// 	for (auto &j : i)
	// 		cout << j << " ";
	// 	cout << "\n";
	// }

	// Check enough left after each flight!
	for (int d = 0; d < n; ++d) // day 
		for (int a = 0; a < k; ++a) { // airport
			int &c = pp[d][a]; // no of people at the start
			for (auto &f : fly[d][a]) { // for each flight
				if (c -= f.first, c < 0) { // nobody left :(
					cout << "suboptimal";
					return 0;
				}
				if (d+1 < n) // fly stragglers to airport
					pp[d+1][f.second] += f.first;			
			}

			if (d+1 < n) // Carry over stragglers to next day
				pp[d+1][a] += c;
		}
	// for (auto &i : pp) {
	// 	for (auto &j : i)
	// 		cout << j << " ";
	// 	cout << "\n";
	// }
	cout << "optimal";

	return 0;
}