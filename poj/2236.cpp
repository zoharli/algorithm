#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(5e5+5)

int n,d;
int x[N],y[N],p[N];
int find(int x){
	if(p[x]==x)return x;
	else return p[x]=find(p[x]);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for (int i = 1; i <= n; i++) {
		cin>>x[i]>>y[i];
	}
	char t;
	while(cin>>t){
		if(t=='O'){
			int q;
			cin>>q;
			if(!p[q]){
				p[q]=q;
				for (int i = 1; i <= n; i++) {
					if(p[i]&&(pow(x[i]-x[q],2)+pow(y[i]-y[q],2)<=d*d)){
						p[find(i)]=find(q);
					}
				}
			}
		}
		else {
			int a,b;
			cin>>a>>b;
			if(find(a)==find(b))cout<<"SUCCESS"<<endl;
			else cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
