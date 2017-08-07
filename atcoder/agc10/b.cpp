#include<bits/stdc++.h>
using namespace std;
long long n,a[100005];
int main(void)
{
	int flag=1;
	long long sum=0;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%((1+n)*n/2)!=0)flag=0;
	long long m=sum/((1+n)*n/2);
	for (int i = 0; i < n; i++) {
		if((a[(i+n-1)%n]-a[i]+m)%n!=0)flag=0;
		if((a[(i+n-1)%n]-a[i]+m)/n <0)flag=0;

	}
	if(flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
