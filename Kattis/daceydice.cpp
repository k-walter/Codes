#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;
enum {UP,DOWN,LEFT,RIGHT,TOP,BTM};
bool flag;
int n,r,c;
char grid[20][20];
set<tuple<int,int,int>> visited; // no hash function

// within bounds, not magnet, not visited
bool valid(const int &y, const int &x, const int &o) {
	return !flag && x>=0 && x<n && y>=0 && y<n && grid[y][x]!='*' && visited.find({y,x,o})==visited.end();
}

int roll_up(const int &o) {
	switch (o) {
		case TOP: return UP;
		case UP: return BTM;
		case BTM: return DOWN;
		case DOWN: return TOP;
		default: return o;
	}
}

int roll_down(const int &o) {
	switch (o) {
		case TOP: return DOWN;
		case DOWN: return BTM;
		case BTM: return UP;
		case UP: return TOP;
		default: return o;
	}
}

int roll_left(const int &o) {
	switch (o) {
		case TOP: return LEFT;
		case LEFT: return BTM;
		case BTM: return RIGHT;
		case RIGHT: return TOP;
		default: return o;
	}
}

int roll_right(const int &o) {
	switch (o) {
		case TOP: return RIGHT;
		case RIGHT: return BTM;
		case BTM: return LEFT;
		case LEFT: return TOP;
		default: return o;
	}
}

void dfs(int y, int x, int o) {
	visited.emplace(y,x,o);
	if (grid[y][x] == 'H' && o == BTM) {
		flag = true; return;
	}

	int oo = roll_right(o);
	if (valid(y,x+1,oo)) dfs(y,x+1,oo);
	oo = roll_down(o);
	if (valid(y+1,x,oo)) dfs(y+1,x,oo);
	oo = roll_left(o);
	if (valid(y,x-1,oo)) dfs(y,x-1,oo);
	oo = roll_up(o);
	if (valid(y-1,x,oo)) dfs(y-1,x,oo);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("daceydice.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) {
		cin>>n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin>>grid[i][j];
				if (grid[i][j] == 'S') {
					r = i; c = j;
				}
			}
		}

		flag = false; visited.clear();
		dfs(r,c,LEFT);
		cout << (flag ? "Yes" : "No") << "\n";
	}

	return 0;
}


	// cout << y << " " << x << " ";
	// switch (o) {
	// 	case TOP: cout << "TOP"; break;
	// 	case BTM: cout << "BTM"; break;
	// 	case LEFT: cout << "LEFT"; break;
	// 	case RIGHT: cout << "RIGHT"; break;
	// 	case UP: cout << "UP"; break;
	// 	case DOWN: cout << "DOWN"; break;
	// }
	// cout << "\n";