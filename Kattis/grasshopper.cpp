#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int dy[]={-2,-2,-1,-1,1,1,2,2}, dx[]={-1,1,-2,2,-2,2,-1,1};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("grasshopper.in", "r", stdin);

	int R,C,ys,xs,yt,xt;
	bool g[100][100];
	queue<ii> q;
	int n,dist;
	while (scanf("%d%d%d%d%d%d",&R,&C,&ys,&xs,&yt,&xt) != EOF) {
		--ys; --xs; --yt; --xt;
		memset(g,0,sizeof g); g[ys][xs]=1;
		dist = 0; q={}; q.emplace(ys,xs);
		while (n = q.size()) {
			while (n--) {
				auto &[yy,xx] = q.front();
				if (yy==yt && xx==xt) { printf("%d\n", dist); goto end; }
				for (int i = 0; i < 8; ++i) {
					const int &y=yy+dy[i], &x=xx+dx[i];
					if (y<0 || y>=R || x<0 || x>=C || g[y][x]) continue;
					g[y][x]=1; q.emplace(y,x);
				}
				q.pop();
			}
			++dist;
		}
		printf("impossible\n");
		end:;
	}

	return 0;
}