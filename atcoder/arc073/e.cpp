#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<int,int>> a;
ll min(ll a,ll b){
	if(a<b){
		return a;
	}
	else return b;
}


int main(void)
{
	cin>>n;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin>>x>>y;
		a.push_back({x,i});
		a.push_back({y,i});
	}
	sort(a.begin(),a.end());
	unordered_map<int,int> map,cast;
	for (int i = 0; i < a.size(); i++) {
		if(!map.count(a[i].second)){
			map[a[i].second]=i;
		}
		else{
			cast[map[a[i].second]]=i;
			cast[i]=map[a[i].second];
		}
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	ll ret=0x3f3f3f3f3f3f3f3f;
	if(a[0].second!=a.back().second){
		int gmax=a.size()-1,gmin=0;
		int rmax=cast[0],rmin=cast[gmax];
		if(rmax<rmin)swap(rmax,rmin);
		for(int i=1;i<rmin;i++){
			if(cast[i]<rmin){
				rmin=min(rmin,max(i,cast[i]));
			}
		}
		for(int i=a.size()-2;i>rmax;i--){
			if(cast[i]>rmax){
				rmax=max(rmax,min(i,cast[i]));
			}
		}
		int flag=0;
		int rmax1=rmax;
		for(int i=1;i<rmin;i++){
			if(cast[i]>rmax){
				flag=1;
				ret=min(ret,ll(a[gmax].first-a[gmin].first)*ll(a[rmax1].first-a[i].first));
				rmax1=max(rmax1,cast[i]);
			}
		}
		if(!flag)ret=min(ret,ll(a[gmax].first-a[gmin].first)*ll(a[rmax].first-a[rmin].first));
		int rmin1=rmin;
		for(int i=a.size()-2;i>rmax;i--){
			if(cast[i]<rmin){
				ret=min(ret,ll(a[gmax].first-a[gmin].first)*ll(a[i].first-a[rmin1].first));
				rmin1=min(rmin1,cast[i]);
			}
		}
	}
	int rmin=0,gmax=a.size()-1;
	int gmin=cast[rmin],rmax=cast[gmax];
	for(int i=1;i<gmin;i++){
		if(cast[i]<gmin){
			gmin=min(gmin,max(cast[i],i));
		}
	}
	for(int i=a.size()-2;i>rmax;i--){
		if(cast[i]>rmax){
			rmax=max(rmax,min(cast[i],i));
		}
	}
	ret=min(ret,ll(a[gmax].first-a[gmin].first)*ll(a[rmax].first-a[rmin].first));
	cout<<ret<<endl;
	return 0;
}
