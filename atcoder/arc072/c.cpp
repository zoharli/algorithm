#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> a;

ll solve(vector<ll> a,int sign){
    vector<ll> sum(a.size()+1);
	ll cnt=0;
	for (int i = 0; i < a.size(); i++) {
		if(sign==-1){
			if(sum[i]+a[i]<0)sum[i+1]=sum[i]+a[i];
			else {
				cnt+=abs(-1-sum[i]-a[i]);
				sum[i+1]=-1;
			}
			sign=1;
		}
		else {
			if(sum[i]+a[i]>0)sum[i+1]=sum[i]+a[i];
			else {
				cnt+=abs(1-sum[i]-a[i]);
				sum[i+1]=1;
			}
			sign=-1;
		}
	}
	return cnt;
}

int main(void)
{
	cin>>n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	ll ret=min(solve(a,1),solve(a,-1));
	cout<<ret<<endl;
	return 0;
}
