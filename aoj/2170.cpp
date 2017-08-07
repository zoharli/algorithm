#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N 200005

int p[N],m[N];

int find(int x){
	if(m[x]!=0)return x;
	else return p[x]=find(p[x]);
}

int main(){
	ios::sync_with_stdio(false);
	int n,q;
	while(cin>>n>>q){
		if(n==0&&q==0)break;
		memset(p,0,sizeof(p));
		memset(m,0,sizeof(m));
		p[1]=1;
		
		m[1]=-1;
		for (int i = 0; i < n-1; i++){
			cin>>p[i+2];
		}
		vector<pair<char,int>> st;
		while(q--){
			char t;
			int x;
			cin>>t>>x;
			st.push_back({t,x});
			if(t=='M'&&m[x]==0){
				m[x]=st.size();
			}
		}
		ll sum=0;
		for(int i=st.size()-1;i>=0;i--){
			if(st[i].fi=='M'){
				if(m[st[i].se]==i+1)m[st[i].se]=0;
			}
			else{
				sum+=find(st[i].se);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
