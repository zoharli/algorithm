#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005

ll n,m,a[N],l[N],r[N],rsub[N],cnt,x,maxx,ret;

int main(int argc, const char *argv[])
{
	cin>>n>>m;
	for (ll i = 0; i < n; i++) {
		cin>>a[i];
		a[i]--;
	}
	for (ll i = 0; i < n-1; i++) {
		l[a[i]]++;
		r[a[i+1]]++;
		rsub[(a[i+1]+1)%m]+=a[i]<a[i+1]?(a[i+1]-a[i]-1):(a[i]+m-a[i+1]-1);
		if(a[i]==m-1&&a[i+1]!=0){
			cnt++;
		}
		else if(a[i+1]==0){
			x+=(0+m-a[i]-1);
		}
		else if(a[i]>a[i+1]){
			x+=(0+m-a[i]-1);
			cnt++;
		}
		if(a[i]<a[i+1]){
			ret+=a[i+1]-a[i];
		}
		else{
			ret+=a[i+1]+m-a[i];
		}
	}
	maxx=x;
	for(ll i=1;i<m;i++){
		x+=cnt;
		x-=rsub[i];
		cnt+=l[i-1];
		cnt-=r[i];
		maxx=max(maxx,x);
	}
	cout<<ret-maxx<<endl;
	return 0;
}
