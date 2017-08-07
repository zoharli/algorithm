#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(1e4+5)

int p[N];
vector<int> g[N];

void init(){
	for (int i = 2; i < N; i++) {
		if(p[i])continue;
		for (int j = 2; i*j < N; j++) {
			p[i*j]=1;
		}
	}		
	vec<int> a;
	for(int i=1000;i<10000;i++){
		if(p[i]==0)a.push_back(i);
	}
	for (int i = 0; i < a.size(); i++){
		for (int j = i+1; j < a.size(); j++){
			int cnt=0,x=a[i],y=a[j];
			for (int k = 0; k < 4; k++){
				if(x%10==y%10)cnt++;
				x/=10;
				y/=10;
			}
			if(cnt==3){
				g[a[i]].push_back(a[j]);
				g[a[j]].push_back(a[i]);
			}
		}
	}
}
int bfs(int u,int v){
	queue<pair<int,int> > q;
	q.push({u,0});
	vector<int> vis(N,0);
	vis[u]=1;
	while(q.size()){
		pair<int,int> x=q.front();
		q.pop();
		if(x.fi==v)return x.se;
		for (int i = 0; i < g[x.fi].size(); i++){
			if(!vis[g[x.fi][i]]){
				q.push({g[x.fi][i],x.se+1});
				vis[g[x.fi][i]]=1;
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	init();
	int T;
	cin>>T;
	while(T--){
		int u,v;
		cin>>u>>v;
		int x=bfs(u,v);
		if(x==-1)cout<<"Impossible"<<endl;
		else cout<<x<<endl;
	}
	return 0;
}
