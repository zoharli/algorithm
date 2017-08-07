#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<ll,ll>> a;

int main(void)
{
	cin>>n;
	int max=0;
	unordered_set<ll> flag;
	for (int i = 0; i < n; i++) {
		int x;
		cin>>x;
		a.push_back({x,i+1});
		if(max<x){
			max=x;
			flag.insert(i+1);
		}
	}		
	a.push_back({0,0});
	flag.insert(0);
	unordered_map<ll,ll> ret;
	sort(a.begin(),a.end());
	int len=a.size();
	for(ll i=len-1,last=a.back().first,lastflag=-1,tmp=0;i>=0;i--){
		tmp+=(last-a[i].first)*(len-1-i);
		if(flag.count(a[i].second)){
			ret[lastflag]=tmp;
			tmp=0;
			lastflag=a[i].second;
		}
		last=a[i].first;
	}
	for(int i=1;i<=n;i++){
		cout<<ret[i]<<endl;
	}
	return 0;
}
