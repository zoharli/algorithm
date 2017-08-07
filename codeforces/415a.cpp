#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int mod=1e9+7;
vector<int> a;

int quick_pow(int a,int n,int mod){
	ll ret=1;
	while(n){
		if(n%2)ret=(ret*ll(a))%mod;
		a=ll(a)*ll(a)%mod;
		n>>=1;
	}
	return ret;
}

int main(void)
{
	cin>>n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll ret=0;
	for (int i = 0; i < n-1; i++) {
		ll b=(quick_pow(2,i+1,mod)+mod-1)%mod;
		b=(b*quick_pow(2,n-1-i,mod)+mod-1)%mod;
		b=b*(a[i+1]-a[i])%mod;
		ret=(ret+b)%mod;
	}
	cout<<ret<<endl;
	return 0;
}
