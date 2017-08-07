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
typedef pair<int,int> P;
#define fi first
#define se second
#define vec vector
const double eps=1e-6;
const int inf=0x3f3f3f3f;
#define N int(5e4+5)

struct E{
	int to,d,cap,rev;
	E(int a,int b,int c,int x):to(a),d(b),cap(c),rev(x){}
};

int n,m,k,h[N];
P pre[N];
vec<E> g[N];

int min_cost_flow(int f){
	int ret=0;
	memset(h,inf,sizeof(h));
	h[1]=0;
	for (int i = 0; i < k-1; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < g[j].size(); k++){
				if(g[j][k].cap>0 && h[g[j][k].to]>h[j]+g[j][k].d){
					h[g[j][k].to]=h[j]+g[j][k].d;
					pre[g[j][k].to]={j,k};
				}
			}
		}
	}
	while(f){
		int d=f;
		for(int i=k;i!=1;i=pre[i].fi){
			d=min(d,g[pre[i].fi][pre[i].se].cap);
		}
		f-=d;
		ret+=d*h[k];
		for(int i=k;i!=1;i=pre[i].fi){
			E &e=g[pre[i].fi][pre[i].se];
			e.cap-=d;
			g[e.to][e.rev].cap+=d;
		}
		int h1[N];
		memset(h1,inf,sizeof(h1));
		h1[1]=0;
		priority_queue<P,vec<P>,greater<P>> q;
		q.push({0,1});
		while(q.size()){
			int to=q.top().se,d=q.top().fi;q.pop();
			if(h1[to]<d)continue;
			for (int i = 0; i < g[to].size(); i++){
				E &e=g[to][i];
				if(e.cap>0 && h1[e.to]>d+e.d+h[to]-h[e.to]){
					h1[e.to]=d+e.d+h[to]-h[e.to];
					pre[e.to]={to,i};
					q.push({h1[e.to],e.to});
				}
			}
		}
		for (int i = 1; i <=k; i++)h[i]+=h1[i];
	}
	return ret;	
}

int w[N],a[N],last[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n>>k;
	for (int i = 0; i < n; i++){
		cin>>w[i+1];
	}
	int sum=0;
	vec<int> p;
	p.push_back(1);
	p.push_back(k);
	for (int i = 1; i <= k; i++) {
		cin>>a[i];
		sum+=w[a[i]];
		if(last[a[i]]){
			p.push_back(i);
			p.push_back(last[a[i]]);
			g[last[a[i]]].push_back(E(i,-w[a[i]],1,g[i].size()));
			g[i].push_back(E(last[a[i]],w[a[i]],0,g[last[a[i]]].size()-1));
		}
		last[a[i]]=i;
	}
	sort(p.begin(),p.end());
	for (int i = 0; i < p.size()-1; i++){
		if(p[i]!=p[i+1]){
			g[p[i]].push_back(E(p[i+1],0,inf,g[p[i+1]].size()));
			g[p[i+1]].push_back(E(p[i],0,0,g[p[i]].size()-1));
		}
	}
	sum+=min_cost_flow(m-1);
	vec<int> vis(N);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < g[i].size(); j++){
			E &e=g[i][j];
			if(e.cap==0 && e.d<0){
				vis[i]=vis[e.to]=1;
			}
		}
	}
	int l=0;
	for (int i = 1; i <= k; i++) {
		if(vis[i]==0){
			if(l && a[l]==a[i]){
				sum-=w[a[i]];
			}
			l=i;
		}
	}
	cout<<sum<<endl;
	return 0;
}
