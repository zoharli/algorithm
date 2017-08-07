#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005

vector<int> e[N];
int dfs(int u,int v){
	int r=0;
	for(auto x:e[v]){
		if(x!=u)r=r^(1+dfs(v,x));
	}
	return r;
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n-1; i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(dfs(0,1))cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
	return 0;
}
