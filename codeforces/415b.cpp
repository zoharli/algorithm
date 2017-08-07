#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;

int solve(int left,int right){
	if(left==right)return left;
	int mid=(left+right)/2;
	cout<<1<<' '<<mid<<' '<<mid+1<<endl;
	string t;
	cin>>t;
	fflush(stdout);
	if(t=="TAK"){
		return solve(left,mid);
	}
	else return solve(mid+1,right);
}
int main(void)
{
	cin>>n>>k;
	int x=solve(1,n);
	int y;
	y=solve(1,x>1?x-1:x);
	string t;
	cout<<1<<' '<<y<<' '<<x<<endl;
	cin>>t;
	fflush(stdout);
	if(t=="NIE"||y==x){
		y=solve(x+1,n);
	}
	cout<<2<<' '<<x<<' '<<y<<endl;
	return 0;
}
