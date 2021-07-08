#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("gradecurving.in", "r", stdin);

	double x; int yl,yh;
	cin>>x>>yl>>yh;
	if (x > yh) {cout<<"impossible"; return 0;}
	int lo=INF,hi;
	for (int i=0;i<10;++i) {
		if (ceil(x) > yh) { hi=i-1; break; }
		if (ceil(x) >= yl) lo = min(lo, i);
		x = 10 * sqrt(x + EPS);
	}
	if (lo == INF) { cout<<"impossible"; return 0; }
	cout<<lo<<" ";
	if (yh == 100) cout<<"inf";
	else cout<<hi;

	return 0;
}
/*
	// 9 steps from 1 --> 99
	// f^n(99) never reach 100

L x H
L 10s(x) H
	L^2 100x H^2
L^2 10s(100x) H^2
	L^4 1e4x H^4
*/