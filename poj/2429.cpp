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
		a=a%b;
		swap(a,b);
	}
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	ll a,b;
	while(cin>>a>>b){
		ll c=b/a;
		for(ll i=sqrt(c);i>=1;i--){
			if(c%i==0 && gcd(i,c/i)==1){
				cout<<i*a<<' '<<c/i*a<<endl;
				break;
			}
		}
	}
	return 0;
}
