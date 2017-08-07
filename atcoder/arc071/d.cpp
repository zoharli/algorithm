#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<ll> x(n),y(m);
	n-=1;
	m-=1;
	ll prev;
	cin>>prev;
	for (int i = 1; i <=n; i++) {
		cin>>x[i];
		int t=x[i];
		x[i]-=prev;
		prev=t;
	}
	cin>>prev;
	for (int i = 1; i <=m; i++) {
		cin>>y[i];
		int t=y[i];
		y[i]-=prev;
		prev=t;
	}
	ll sum=0;
	for (int i = 1; i <= m; i++){
		sum=(sum+y[i]*i*(m-i+1))%MOD;
	}
	ll sum1=0;
	for (int i = 1; i <= n; i++){
		sum1=(sum1+x[i]*i*(n-i+1))%MOD;
	}
	sum=(sum*sum1)%MOD;
	cout<<sum<<endl;
	return 0;
}
