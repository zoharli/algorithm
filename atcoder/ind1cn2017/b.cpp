#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i,int n,int cursum, int& sum,vector<int>& a,vector<int>& b, vector<int>& c,vector<int>& d){
	if(i==n){
	sum=min(sum,cursum);
	return;
	}
	for(int j=i;j<n;j++){
		int tmp1=c[i],tmp2=d[i];
		c[i]=c[j];
		d[i]=d[j];
		c[j]=tmp1;
		d[j]=tmp2;
		cursum+=abs(a[i]-c[i])+abs(b[i]-d[i]);
		dfs(i+1,n,cursum,sum,a,b,c,d);
		cursum-=abs(a[i]-c[i])+abs(b[i]-d[i]);
		tmp1=c[i],tmp2=d[i];
		c[i]=c[j];
		d[i]=d[j];
		c[j]=tmp1;
		d[j]=tmp2;
	}
	return;
}

int main(void)
{
	int n,t;
	cin>>n>>t;
	vector<int> a(n),b(n),c(n),d(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i]>>b[i];
	}
	int totsum=0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			cin>>c[j]>>d[j];
		}
		int sum=0x3f3f3f3f;
		dfs(0,n,0,sum,a,b,c,d);
		totsum+=sum;
		a=c;
		b=d;
	}
	cout<<totsum<<endl;
	return 0;
}
