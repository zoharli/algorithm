#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,n;
vector<ll> r,x,rpre,rsuf,xrpre,xrsuf;

ll min(ll a,ll b){
	if(a>b)return b;
	else return a;
}

int main(void)
{
	cin>>l>>n;
	r.resize(n+2);
	x=rpre=rsuf=xrpre=xrsuf=r;
	for (int i = 1; i <= n; i++) {
		cin>>x[i]>>r[i];
	}
	
	for (int i = 1; i <= n; i++) {
		rpre[i]=rpre[i-1]+r[i];
		xrpre[i]=xrpre[i-1]+r[i]*x[i];
	}
	for (int i=n;i>=1;i--){
		rsuf[i]=rsuf[i+1]+r[i];
		xrsuf[i]=xrsuf[i+1]+r[i]*x[i];
	}
	ll ret=9223372036854775807;
	for (int i = 1; i <n; i++) {
		ll sum=0-xrpre[i]+xrsuf[i+1];
		if(rpre[i]>=rsuf[i+1]){
			ret=min(ret,sum+x[i]*(rpre[i]-rsuf[i+1]));
		}
		else ret=min(ret,sum+x[i+1]*(rpre[i]-rsuf[i+1]));
	}
	if(n==1)cout<<0<<endl;
	else cout<<ret<<endl;
	return 0;
}
