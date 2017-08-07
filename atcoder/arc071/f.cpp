#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n;
int main(void)
{
	cin>>n;
	vector<ll> dp(n);
	vector<ll> sum(n);
	for (int i = 0; i < n; i++) {
		if(i==0){
			dp[i]=n%mod;
			sum[i]=(dp[i]+n-1)%mod;
			continue;
		}
		else if(i==1){
			dp[i]=n*n%mod;
		}
		else if(i==2){
			dp[i]=(dp[i-1]+(n-1)*n)%mod;
		}
		else {
			dp[i]=(dp[i-1]+sum[i-3]+n*(n-i+1))%mod;
		}
		sum[i]=(sum[i-1]+dp[i]+n-1)%mod;
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
