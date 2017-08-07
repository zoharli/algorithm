#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,w;
vector<int> a,v;

int main(void)
{
	cin>>n>>w;
	a.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i]>>v[i];
	}
	unordered_map<ll,ll> mp[2];
	mp[0][0]=0;
	int k=0;
	for (int i = 0; i < n; i++) {
		mp[!k][0]=0;
		for(auto x:mp[k]){
			mp[!k][x.first]=max(mp[!k][x.first],mp[k][x.first]);
			mp[!k][x.first+a[i]]=max(mp[!k][x.first+a[i]],x.second+v[i]);
		}
		k=!k;
	}
	mp[k][0]=0;
	int ret=0;
	for(auto x:mp[k]){
		if(x.first<=w){
			ret=max(ret,int(x.second));
		}
	}
	cout<<ret<<endl;
	return 0;
}
