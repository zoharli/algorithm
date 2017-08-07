#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> h;
int a,b;

bool solve(int k){
	int t=0;
	for (int i = 0; i < h.size(); i++) {
		ll tmp=ll(h[i])-ll(k)*ll(b);
		if(tmp>0)t+=ceil(float(tmp)/(a-b));
	}
	return k>=t;
}

int main(void)
{
	cin>>n>>a>>b;
	for (int i = 0; i < n; i++) {
		int t;
		cin>>t;
		h.push_back(t);
	}
	int l=1,r=int(1e9);
	while(l<r){
		int mid=(l+r)/2;
		if(solve(mid)){
			r=mid;
		}
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
