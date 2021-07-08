#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int r,c; 
vector<string> a(r);
struct Trie {
	int unq = -1;
	Trie *a[26] = {NULL};
};
Trie *root = new Trie;

inline int solve(int u) {
	int v = -1;
	Trie *cur = root;
	for (int i=r-1;i>0;--i) {
		char c = a[i][u] - 'a';
		// if isNew
		if (!cur->a[c]) {
			cur->a[c] = new Trie;
			cur->a[c]->unq = u;
			return i;
		}
		cur = cur->a[c];
		// if isTerm, expand term
		if (cur->unq == -1) continue;
		c = a[i-1][cur->unq] - 'a';
		cur->a[c] = new Trie;
		cur->a[c]->unq = cur->unq;
		cur->unq = -1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("znanstvenik.in", "r", stdin);

	cin>>r>>c; cin.get();
	a.resize(r);
	for (auto &s:a) cin>>s;
	int ans=r;
	for (int i=0;ans and i<c;++i) { ans=min(ans,solve(i)); }
	cout<<ans;

	return 0;
}