#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
int main(void)
{
	cin>>n;
	int flag=0;
	int minv=101;
	int sum=0;
	for (int i = 0; i < n; i++) {
		int t;
		cin>>t;
		a.push_back(t);
		sum+=t;
		if(t%10!=0){
		flag=1;
		minv=min(minv,t);
		}
	}
	if(flag){
		if(sum%10==0)sum-=minv;
	}
	else {
		sum=0;
	}
	cout<<sum<<endl;
	return 0;
}
