#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("4a.in", "r", stdin);

	int n;cin>>n;
	cout<<((n<4 or (n&1))?"NO":"YES");

	return 0;
}