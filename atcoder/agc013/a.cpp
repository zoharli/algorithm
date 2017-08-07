#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005

int n;
vector<int> a;

int solve(int x){
	if(n-x<=2)return 1;
	int s=a[x+1]>a[x];
	for (int i = x; i < n-1; i++) {
		if(s && a[i+1]<a[i]){
			return solve(i+1)+1;
		}
		else if( !s && a[i+1]>a[i]){
			return solve(i+1)+1;
		}
	}
	return  1;
}

int main(void)
{
	int prev=1e9+7;
	cin>>n;
	for (int i = 0; i < n; i++) {
		int b;
		cin>>b;
		if(b!=prev){
			a.push_back(b);
		}
		prev=b;
	}
	n=a.size();
	int ret=solve(0);
	cout<<ret<<endl;
	return 0;
}
