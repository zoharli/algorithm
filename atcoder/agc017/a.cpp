#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005

ll n,p,a[55],o[55],e[55];

int main(){
	cin>>n>>p;
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	e[0]=1;
	for (int i = 0; i < n; i++){
		if(a[i]%2){
			o[i+1]=o[i]+e[i];
			e[i+1]=e[i]+o[i];
		}
		else {
			o[i+1]=2*o[i];
			e[i+1]=2*e[i];
		}
	}
	if(p==0)cout<<e[n]<<endl;
	else cout<<o[n]<<endl;
	return 0;
}
