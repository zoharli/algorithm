#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
int solve(){
	int ret=0;
	while(a%2==0 && b%2==0 && c%2==0){
		if(a==b && b==c)return -1; 
		ll ta,tb,tc;
		ta=(b+c)/2;
		tb=(a+c)/2;
		tc=(a+b)/2;
		a=ta;
		b=tb;
		c=tc;
		ret++;
	}
	return ret;
}
int main(void)
{
	cin>>a>>b>>c;
	cout<<solve()<<endl;
	return 0;
}
