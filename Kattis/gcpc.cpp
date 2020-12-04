#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
typedef pair<int,int> score;
typedef tuple<int,int,int> team;

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("gcpc.in", "r", stdin);

	int n, m; cin >> n >> m;
	vector<score> ntos(n+1, {0,0});
	pbds_set<team> os; // DSC problems, ASC penalty, ASC team
	int t,p;
	auto &[n1,p1] = ntos[1];
	while (m--) {
		cin >> t >> p;
		auto &[no,pe] = ntos[t];
		if (no) os.erase({no, pe, t});
		--no; pe += p;
		os.insert({no, pe, t});
		cout << os.order_of_key({n1, p1, 1}) + 1 << "\n";
	}

	return 0;
}