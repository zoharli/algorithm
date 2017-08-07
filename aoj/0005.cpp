#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(5e5+5)

ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(a%b){
		ll t=a%b;
		a=b;
		b=t;
	}
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	ll a,b;
	while(cin>>a>>b){
		ll g=gcd(a,b);
		ll lcm=g*(a/g)*(b/g);
		cout<<g<<' '<<lcm<<endl;
	}
	return 0;
}
