#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005
int n,m,q;
map<string,int> mp;
int syn[MAXN];

int *uf;
void uf_init(){
	for (int i = 0; i < MAXN; i++) {
		uf[i]=i;
	}
}
int uf_find(int i){
	if(uf[i]!=i){
		return uf[i]=uf_find(uf[i]);
	}
	else return i;
}
int uf_merge(int i,int j){
	i=uf_find(i);
	j=uf_find(j);
	return uf[i]=uf[j]=min(uf[i],uf[j]);
}
int ant[MAXN];
int update(int t,string s1,string s2){
	int i=mp[s1],j=mp[s2];
	if(t==1){
		if(uf_find(ant[uf_find(i)])==uf_find(j))return 0;
		int b=0;
		if(ant[uf_find(i)]&&ant[uf_find(j)]){
			b=uf_merge(ant[uf_find(i)],ant[uf_find(j)]);
		}
		else if(ant[uf_find(i)])b=uf_find(ant[uf_find(i)]);
		else if(ant[uf_find(j)])b=uf_find(ant[uf_find(j)]);
		int a=uf_merge(i,j);
		ant[a]=b;
		if(b)ant[b]=a;
	}
	else {
		if(uf_find(i)==uf_find(j))return 0;
		if(ant[uf_find(i)]){
			uf_merge(j,ant[uf_find(i)]);
		}
		if(ant[uf_find(j)]){
			uf_merge(i,ant[uf_find(j)]);
		}
		ant[uf_find(i)]=uf_find(j);
		ant[uf_find(j)]=uf_find(i);
	}
	return 1;
}
int main(void)
{
	cin>>n>>m>>q;
	uf=syn;
	uf_init();

	for (int i = 0; i < n; i++) {
		string s;
		cin>>s;
		mp[s]=i+1;
	}
	for (int i = 0; i < m; i++) {
		int t;
		string s1,s2;
		cin>>t>>s1>>s2;
		if(update(t,s1,s2)){
			cout<<"YES"<<endl;
		}
		else cout << "NO" << endl;
	}
	for (int i = 0; i < q; i++) {
		string s1,s2;
		cin>>s1>>s2;
		int a=uf_find(mp[s1]),b=uf_find(mp[s2]);
		if(a==b)cout<<1<<endl;
		else if(ant[a]==b)cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
