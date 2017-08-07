#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define vec vector
const double eps=1e-6;
const int inf=0x3f3f3f3f;
#define N int(1e2+5)

int n,m,h[2*N],h1[2*N],prevv[2*N],preve[2*N];
struct E{
	int to,d,cap,rev;
	E(int a,int b,int c,int d):to(a),d(b),cap(c),rev(d){}
};
vec<E> g[N];

void clear(){
	for(int i=0;i<N;i++)g[i].clear();
}

void add_edge(int from,int to,int d,int cap){
	g[from].push_back(E(to,d,cap,g[to].size()));
	g[to].push_back(E(from,-d,0,g[from].size()-1));
}

int min_cost_flow(int f,int s,int t){
	int ret=0;
	memset(h,0,sizeof(h));
	while(f){
		memset(h1,inf,sizeof(h1));
		h1[s]=0;
		priority_queue<P,vec<P>,greater<P>> q;
		q.push({0,s});
		while(q.size()){
			int d=q.top().fi,v=q.top().se;q.pop();
			if(h1[v]<d)continue;
			for (int i = 0; i < g[v].size(); i++){
				E &e=g[v][i];
				if(e.cap>0 && h1[e.to]>d+e.d+h[v]-h[e.to]){
					h1[e.to]=d+e.d+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					q.push({h1[e.to],e.to});
				}
			}
		}
		for (int i = 0; i < N; i++)h[i]+=h1[i];
		int d=f;
		for(int i=t;i!=s;i=prevv[i])d=min(d,g[prevv[i]][preve[i]].cap);
		for(int i=t;i!=s;i=prevv[i]){
			E &e=g[prevv[i]][preve[i]];
			e.cap-=d;
			g[e.to][e.rev].cap+=d;
		}
		f-=d;
		ret+=d*h[t];
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		if(n==0 && m==0)break;
		clear();
		vec<vec<int> > board(n,vec<int>(m)),vis=board,zero=board;
		int cnt=0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c;
				cin>>c;
				if(c=='.')board[i][j]=-1;
				else if(c=='H')board[i][j]=++cnt;
			}
		}
		int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
		int man=0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if(!board[i][j]){
					man++;
					vis=zero;
					vis[i][j]=1;
					queue<P> q;
					q.push({i,j});
					while(q.size()){
						P p=q.front();q.pop();
						for (int k = 0; k < 4; k++){
							int x=p.fi+dx[k],y=p.se+dy[k];
							if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
								vis[x][y]=vis[p.fi][p.se]+1;
								q.push({x,y});
								if(board[x][y]>0){
									add_edge(man,cnt+board[x][y],vis[x][y]-1,1);
								}
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= cnt; i++) {
			add_edge(0,i,0,1);
			add_edge(cnt+i,2*cnt+1,0,1);
		}
		if(cnt==0)cout<<0<<endl;
		else cout<<min_cost_flow(cnt,0,2*cnt+1)<<endl;
	}
	return 0;
}
