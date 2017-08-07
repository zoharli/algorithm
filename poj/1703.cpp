#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(1e5+5)

int p[N],q[N],n,m,T;
int find(int x){
	if(x==p[x])return x;
	else return p[x]=find(p[x]);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for (int i = 1; i <= n; i++) {
			p[i]=i;
		}
		memset(q,0,sizeof(q));
		for (int i = 0; i < m; i++){
			int a,b;
			char t;
			cin>>t>>a>>b;
			a=find(a);
			b=find(b);
			if(t=='D'){
				if(q[a])p[q[a]]=b;
				if(q[b])p[q[b]]=a;
				q[a]=b;
				q[b]=a;
			}
			else {
				if(a==b)cout<<"In the same gang."<<endl;
				else if(q[a]==b)cout<<"In different gangs."<<endl;
				else cout<<"Not sure yet."<<endl;
			}
		}
	}
	return 0;
}
