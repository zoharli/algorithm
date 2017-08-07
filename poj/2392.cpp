#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(4e4+5)

int k,h[405],c[405],a[405],vis[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>k;
	vec<pair<int,pair<int,int>>> tmp;
	for (int i = 0; i < k; i++){
		int h,a,c;
		cin>>h>>a>>c;
		tmp.push_back({a,{h,c}});
	}
	sort(tmp.begin(),tmp.end());
	for (int i = 0; i < k; i++){
		a[i]=tmp[i].fi;
		h[i]=tmp[i].se.fi;
		c[i]=tmp[i].se.se;
	}
	vis[0]=1;
	for (int i = 0; i < k; i++){
		for(int j=a[i];j>=1;j--){
			if(vis[j])continue;
			for(int l=1;l<=c[i];l++){
				if(j-l*h[i]>=0 && vis[j-l*h[i]]){
					vis[j]=1;
					break;
				}
			}
		}
	}
	for(int i=N-1;i>=0;i--){
		if(vis[i]){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
