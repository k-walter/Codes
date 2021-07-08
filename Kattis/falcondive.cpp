#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("falcondive.in", "r", stdin);

	int n,m; char C,_;
	char g[1000][1000];
	while (cin>>n>>m>>_>>C>>_, !cin.eof()) {
		cin.get();
		vii fal;
		for (int i=0;i<n;++i) {
			string s; getline(cin, s);
			for (int j=0;j<m;++j) {
				char c = s[j];
				if (c != C) { g[i][j]=c; continue; }
				fal.emplace_back(i,j);
			}
		}
		cin.get();
		auto it = fal.begin();
		for (int i=0;i<n;++i) {
			string s; getline(cin, s);
			for (int j=0;j<m;++j) {
				char c = s[j];
				if (c != C) { g[i][j]=c; continue; }
				int dy=i-(it->first), dx=j-(it->second);
				it->first += (dy << 1);
				it->second += (dx << 1);
				++it;
			}
		}
		for (auto &it:fal) {
			int i,j; tie(i,j) = it;
			if (i<0 or i>=n or j<0 or j>=m) continue;
			g[i][j]=C;
		}
		for (int i=0;i<n;++i) {
			for (int j=0;j<m;++j) {
				cout<<g[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
		

	return 0;
}