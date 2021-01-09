#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("turtlemaster.in", "r", stdin);

	vector<vc> g(8, vc(8));
	for (vc &row: g) for (char &i : row) cin >> i;
	cin.get();
	string line; getline(cin,line);
	int yy=7, xx=0, d=0, y, x; bool ok = 1;
	int dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
	g[yy][xx]='.';
	for (char &c : line) {
		// cout << "y " << yy << " x " << xx << " " << c << "\n";
		switch (c) {
			case 'F':
				y = yy+dy[d], x = xx+dx[d];
				if (y<0 || y>=8 || x<0 || x>=8) { ok=0; break; }
				if (g[y][x] != '.' && g[y][x] != 'D') { ok=0; break; }
				yy=y; xx=x; break;
			case 'L': if (--d<0) d=3; break;
			case 'R': if (++d>3) d=0; break;
			case 'X':
				y = yy+dy[d], x = xx+dx[d];
				if (y<0 || y>=8 || x<0 || x>=8) { ok=0; break; }
				if (g[y][x] != 'I') { ok=0; break; }
				g[y][x] = '.'; break;
		}
		if (!ok) break;
	}
	if (ok && g[yy][xx]=='D') cout << "Diamond!";
	else cout << "Bug!";

	return 0;
}