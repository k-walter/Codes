#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main() {
	int V = 9; // 9 vertices
	// 9 edges
	vector<ii> EL; 
	EL.emplace_back(0,1); 
	EL.emplace_back(0,5); 
	EL.emplace_back(1,4); 
	EL.emplace_back(2,0); 
	EL.emplace_back(2,1); 
	EL.emplace_back(2,4); 
	EL.emplace_back(5,3); 
	EL.emplace_back(6,7); 
	EL.emplace_back(6,8);
	
	int p[10];
	for (int i = 0; i < V; ++i) p[i] = i;
	int ans = 0;
	do {
		bool valid = true;
		for (auto &[u,v] : EL) {
			int pos_u, pos_v;
			for (pos_u = 0; pos_u < V; ++pos_u) if (p[pos_u] == u) break;
			for (pos_v = 0; pos_v < V; ++pos_v) if (p[pos_v] == v) break;
			if (pos_u > pos_v) { valid = false; break; }
		}
		if (valid) ans++;
	}
	while (next_permutation(p, p+V));
	printf("There are %d valid topological orderings\n", ans);

	return 0;
}