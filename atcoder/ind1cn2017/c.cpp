#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ret;
unordered_map<int,unordered_map<int,int>> mp;
vector<vector<int>> g;
map<int,int> cast1;
map<int,int> cast2;
void check(int i,vector<int>& vis){
	vis[i]=1;
    for(int j=1;j<=n;j++){
		if(!vis[j]){
			if(g[i][j]){
			 check(j,vis);	
			}
		}
	}
}
void dfs(int i,int e){
	if(i==e){
		vector<int> vis(n+1,0);
		check(1,vis);
		for (int i = 1; i <= n; i++){
			if(vis[i]==0){
				return;
			}
		}
		ret++;
		return;
	}
	if(mp[cast1[i]][cast2[i]]==0)dfs(i+1,e);
	g[cast1[i]][cast2[i]]=0;
	g[cast2[i]][cast1[i]]=0;
	dfs(i+1,e);
	g[cast1[i]][cast2[i]]=1;
	g[cast2[i]][cast1[i]]=1;
	
	return;
}
int main(void)
{
	cin>>n>>m;
	g=vector<vector<int>>(n+1,vector<int>(n+1,1));
	for (int i = 0; i < m; i++) {
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
		mp[b][a]=1;
	}
	int cnt=0,e=0;
	for (int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			e++;
			cast1[cnt]=i;
			cast2[cnt++]=j;
		}
	}
	dfs(0,e);
	cout<<ret<<endl;
	return 0;
}
