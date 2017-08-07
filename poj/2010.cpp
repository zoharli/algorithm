#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const ll INF=0x3f3f3f3f3f3f;
#define N int(5e5+5)

int n,c,f;
vector<pair<int,int>> a;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>c>>f;
	for (int i = 0; i < c; i++){
		int x,y;
		cin>>x>>y;
		a.push_back({x,y});
	}
	sort(a.begin(),a.end());
	if(n==1){
		for(int i=a.size()-1;i>=0;i--){
			if(a[i].se<=f){
				cout<<a[i].fi<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
		return 0;
	}
	vec<ll> pre(c,INF),suf=pre;
	pre[(n-1)/2-1]=0;
	suf[c-(n-1)/2]=0;
	priority_queue<int> q1,q2;
	int i=0,j=a.size()-1;
	for(;i<(n-1)/2;i++,j--){
		q1.push(a[i].se);
		q2.push(a[j].se);
		pre[(n-1)/2-1]+=a[i].se;
		suf[c-(n-1)/2]+=a[j].se;
	}
	for(;j>(n-1)/2;i++,j--){
		if(q1.top()>a[i].se){
			pre[i]=pre[i-1]+a[i].se-q1.top();
			q1.pop();
			q1.push(a[i].se);
		}
		else pre[i]=pre[i-1];
		if(q2.top()>a[j].se){
			suf[j]=suf[j+1]+a[j].se-q2.top();
			q2.pop();
			q2.push(a[j].se);
		}
		else suf[j]=suf[j+1];
	}
	for(int i=c-(n+1)/2;i>=(n-1)/2;i--){
		if(a[i].se+pre[i-1]+suf[i+1]<=f){
			cout<<a[i].fi<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
