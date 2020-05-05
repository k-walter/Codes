#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

int w,IS,BR,BU,h = 0;
char ng;
string g[80];
bool vis[80][80];
deque<ii> q;

void flood(int &r, int &c) {
	++BU;
	vis[r][c] = 1; q.emplace_front(r,c);
	if (g[r][c]=='X' || g[r][c]=='#')
		// ++IS;
		{++IS; cout<<"island at "<<r<<" "<<c<<"\n";}

	while (q.size()) {
		auto [yy,xx] = q.front(); q.pop_front();
		switch (g[yy][xx]) { // set no go
			case 'B': ng='#'; break;
			case '#': ng='B'; break;
			case 'X': ng=' '; break; // to prevent reuse
		}

		for (int i = 0; i < 4; ++i) {
			const int &y=yy+dy[i], &x=xx+dx[i];
			if (y<0 || y>=h || x<0 || x>=w) continue;
			if (vis[y][x] || g[y][x]=='.' || g[y][x]==ng) continue;

			vis[y][x] = 1;
			switch (g[y][x]) {
				case 'B':
					if (g[yy][xx]=='X')
						// ++BR;
						{++BR; cout<<"bridge at "<<y<<" "<<x<<"\n";}
					q.emplace_back(y,x); // expand bridges after islands
					break;
				case 'X':
					if (g[yy][xx]=='B')
						// ++IS;
						{++IS; cout<<"island at "<<y<<" "<<x<<"\n";}
				case '#':
					q.emplace_front(y,x); // explore islands first
					break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("island.in", "r", stdin);

	// islands: B->X, +1
	// bridges: X->B, +1
	// buses = no of CC
	// B->{X,B}, X->{#,B,X}, #->{#,X}

	int map_no = 1;
	while (getline(cin, g[h]), 1) {
		if (g[h]!="" && ++h<80) continue; // input possible

		w = g[0].length(); IS=BR=BU=0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (!vis[i][j] && g[i][j]!='.')
					// flood(i,j);
					{ flood(i,j); cout <<"\n"; }

		cout << "Map " << map_no++ << "\nislands: " << IS << "\nbridges: " << BR << "\nbuses needed: " << BU << "\n\n";

		h = 0;
		if (cin.eof()) break;
	}

	return 0;
}