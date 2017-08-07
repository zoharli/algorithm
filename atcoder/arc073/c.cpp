#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,t;
int main(void)
{
	cin>>n>>t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int prev=0;
	ll ret=0;
	for(auto x:a){
		if(x-prev>=t)ret+=t;
		else ret+=x-prev;
		prev=x;
	}
	cout<<ret+ll(t)<<endl;
	return 0;
}
