#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int,int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};
enum {UP=0, RIGHT, DOWN, LEFT};
int r,c,n,m; 
ii rob[101];
int g[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("crashingrobots.in", "r", stdin);

	memset(g,0,sizeof g);
	int tc; cin>>tc;
	while (tc--) {
		cin>>c>>r>>n>>m;
		for (int i=0;i<r;++i) for (int j=0;j<c;++j) g[i][j]=0;
		for(int i=1;i<=n;++i) {
			auto &[y,x,d] = rob[i];
			char c; cin>>x>>y>>c;
			--x; --y; g[y][x]=i;
			switch(c){
				case 'N': d=DOWN; break;
				case 'E': d=RIGHT; break;
				case 'S': d=UP; break;
				case 'W': d=LEFT; break;
			}
		}
		bool ok=1;
		while(m--){
			int u,re; char a;
			cin>>u>>a>>re;
			// cout<<u<<a<<re<<'\n';
			if (!ok) continue;
			auto &[y,x,d]=rob[u];
			switch(a){
				case 'L': d=(d+re)&3; break;
				case 'R': d=(4+d-(re&3))%4; break;
				case 'F':
					g[y][x]=0;
					while (re--) {
						y+=dy[d]; x+=dx[d];
						// cout<<y<<","<<x<<" ";
						if (y<0 or y>=r or x<0 or x>=c) {
							cout<<"Robot "<<u<<" crashes into the wall\n";
							ok=0; break;
						}
						if (g[y][x]) {
							cout<<"Robot "<<u<<" crashes into robot "<<g[y][x]<<"\n";
							ok=0; break;
						}
					}
					if (ok) g[y][x]=u;
					break;
			}
		}
		if(ok)cout<<"OK\n";
		// for(int i=1;i<=n;++i) {
		// 	auto &[y,x,_]=rob[i];
		// 	g[y][x]=0;
		// }
		// cout<<"FIN\n";
	}


	return 0;
}