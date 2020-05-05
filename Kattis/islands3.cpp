#include <bits/stdc++.h>
using namespace std;

int r,c, cc=0;
char grid[50][50];
bool visit[50][50] = {false};
int dy[] = {-1,1,0,0}; // u,d,l,r
int dx[] = {0,0,-1,1};

bool valid(const int &y, const int &x) {
	return y>=0 && y<r && x>=0 && x<c && !visit[y][x] && grid[y][x]!='W';
}

void floodfill(const int &y, const int &x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; ++i)
		if (valid(y+dy[i], x+dx[i])) floodfill(y+dy[i], x+dx[i]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("islands3.in", "r", stdin);

	cin>>r>>c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> grid[i][j];

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (grid[i][j]=='L' && !visit[i][j]) {
				// cout << i << " " << j << "\n";
				floodfill(i,j);
				++cc;
			}
		}
	}

	cout << cc;
	return 0;
}