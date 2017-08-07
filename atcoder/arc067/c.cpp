#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> prime;
const ll mod=1e9+7;

int main(void)
{
	ll n;
	cin>>n;
	for (ll i = 2; i <=n; i++){
		ll d=2,k=i;
		while(d<=k){
			while(k%d==0){
				k/=d;
				prime[d]++;
			}
			d++;
		}
	}
	ll ret=1;
	for(auto x:prime){
		ret=(ret*(x.second+1))%mod;
	}
	cout<<ret<<endl;
	return 0;
}
