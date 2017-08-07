#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N int(2e5+5)

struct e{
	int to,d,c;
	e(int x,int y,int z):to(x),d(y),c(z){}
};
int n,m,s[N];
bool operator<(e e1,e e2){
	if(e1.d!=e2.d)return e1.d>e2.d;
	else return e1.c>e2.c;
}

ll dijkstra(vector<e> g[]){
	memset(s,0,sizeof(s));
	int cnt=1;
	priority_queue<e> q;
	vector<int> dist(n+1,INF);
	dist[1]=0;
	for(int i=0;i<g[1].size();i++){
		q.push(g[1][i]);
		dist[g[1][i].to]=g[1][i].d;
	}
	s[1]=1;
	ll ret=0;
	while(cnt<n){
		while(s[q.top().to])q.pop();
		e x=q.top();
		q.pop();
		ret+=x.c;
		s[x.to]=1;
		for(int i=0;i<g[x.to].size();i++){
			if(dist[g[x.to][i].to]>=x.d+g[x.to][i].d){
				dist[g[x.to][i].to]=x.d+g[x.to][i].d;
				q.push(e(g[x.to][i].to,dist[g[x.to][i].to],g[x.to][i].c));
			}
		}
		cnt++;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		if(n==0 && m==0)break;
		vector<e> g[N];
		int u,v,d,c;
		for (int i = 0; i < m; i++){
			cin>>u>>v>>d>>c;
			g[u].push_back(e(v,d,c));
			g[v].push_back(e(u,d,c));
		}
		cout<<dijkstra(g)<<endl;
	}
	return 0;
}
