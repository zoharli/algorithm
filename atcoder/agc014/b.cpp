#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
unordered_map<int,int> mp;

bool solve(){
	for(auto x:mp){
		if(x.second%2!=0)return 0;
	}
	return 1;
}
int main(void)
{
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int a,b;
		cin>>a>>b;
		mp[a]++;
		mp[b]++;
	}
	if(solve())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
