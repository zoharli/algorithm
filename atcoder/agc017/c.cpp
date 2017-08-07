#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005

int vis[N],cnt[N],n,m,a[N];

int main(){
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		for(int j=max(1,i-cnt[i]+1);j<=i;j++){
			vis[j]++;
		}
	}
	int ret=0;
	for (int i = 1; i <= n; i++) {
		if(!vis[i])ret++;
	}
	for (int i = 0; i < m; i++){
		int x,y;
		cin>>x>>y;
		if(a[x]-cnt[a[x]]+1>0 && --vis[a[x]-cnt[a[x]]+1]==0)ret++;
		cnt[a[x]]--;
		cnt[y]++;
		if(y-cnt[y]+1>0 && ++vis[y-cnt[y]+1]==1)ret--;
		cout<<ret<<endl;
		a[x]=y;
	}
	return 0;
}
