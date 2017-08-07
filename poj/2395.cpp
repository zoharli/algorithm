#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
const int N=2e3+5;
const int M=1e4+5;

vector<pair<int,pair<int,int>>> a;
int s[N],pa[N];
int find(int x){
	if(pa[x]==x)return x;
	else return pa[x]=find(pa[x]);
}

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < N; i++){
		pa[i]=i;
	}
	for (int i = 0; i < m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		a.push_back({z,{y,x}});
	}
	sort(a.begin(),a.end());
	int ret=0;
	for(auto x:a){
		int p=x.se.fi,q=x.se.se;
		if(find(p)!=find(q)){
			pa[pa[p]]=pa[q];
			ret=max(ret,x.fi);
		}
	}
	cout<<ret<<endl;
	return 0;
}
