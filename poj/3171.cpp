#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const double eps=1e-6;
const int inf=0x3f3f3f3f;
#define N int(1e5+5)

int n,m,e;
vec<pair<int,int> > g[N];
vec<int> p;

int dijkstra(){
	vec<int> vis(N),dist(N,inf);
	dist[m]=0;
	priority_queue<pair<int,int>,vec<pair<int,int> >,greater<pair<int,int> > > q;
	vis[m]=1;
	for (int i = 0; i < g[m].size(); i++){
		q.push(g[m][i]);
		dist[g[m][i].se]=g[m][i].fi;
	}
	while(q.size()){
		int to=q.top().se,d=q.top().fi;q.pop();
		if(vis[to])continue;
		vis[to]=1;
		for (int i = 0; i < g[to].size(); i++){
			int to1=g[to][i].se,d1=g[to][i].fi;
			if(!vis[to1] && d+d1<dist[to1]){
				dist[to1]=d+d1;
				q.push({dist[to1],to1});
			}
		}
	}
	return dist[e+1];
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>e;
	for (int i = 0; i < n; i++){
		int t1,t2,s;
		cin>>t1>>t2>>s;
		g[t1].push_back({s,t2+1});
		p.push_back(t1);
		p.push_back(t2+1);
	}
	sort(p.begin(),p.end());
	for (int i = p.size()-1; i>=1;i--){
		if(p[i]>p[i-1])g[p[i]].push_back({0,p[i-1]});
	}
	int ret=dijkstra();
	if(ret==inf)cout<<-1<<endl;
	else cout<<ret<<endl;
	return 0;
}
