#include <bits/stdc++.h>
using namespace std;

bool flag;
unordered_map<string,int> status;
unordered_map<string,vector<string>> al;

void dfs(const string &i) {
	status[i] = 1;

	for (const string &j : al[i]) {
		switch (status[j]) {
			case 0: dfs(j); break;
			case 1:	flag = true; return; // status[i] == status[j] == 1
			case 2: continue; // fully explored
		}
	}

	status[i] = 2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("runningmom.in", "r", stdin);

	int n; cin>>n;
	al.clear();
	while (n--) {
		string a,b; cin>>a>>b;
		al[a].emplace_back(b);
	}

	string line; cin.get();
	while (getline(cin,line), !cin.eof()) {
		flag = false; status.clear();
		dfs(line);
		cout << line << " " << (flag ? "safe" : "trapped") << "\n";
	}

	return 0;
}