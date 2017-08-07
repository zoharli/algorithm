#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a,b;
int main(void)
{
	cin>>n>>a>>b;
	ll ret=0;
	ll prev;
	cin>>prev;
	for (int i = 1; i < n; i++) {
		int t;
		cin>>t;
		if((t-prev)*a>=b)ret+=b;
		else ret+=(t-prev)*a;
		prev=t;
	}
	cout<<ret<<endl;
	return 0;
}
