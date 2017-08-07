#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define ve vector
const ll INF=0x3f3f3f3f3f3f;

void floyd(vector<vector<ll>> &a,ll n){
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			for (ll k = 1; k <= n; k++) {
				a[k][j]=a[j][k]=min(a[j][i]+a[i][k],a[j][k]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	ll n,m;
	while(cin>>n>>m){
		if(n==0 && m==0)break;
		vector<vector<ll>> s(n+1,vector<ll>(n+1,INF));
		for (ll i = 1; i <= n; i++) {
			s[i][i]=0;
		}
		vector<vector<ll>> l=s;
		for (ll i = 0; i < m; i++){
			ll x,y,t;
			char sl;
			cin>>x>>y>>t>>sl;
			if(sl=='S'){
				s[y][x]=s[x][y]=min(s[x][y],t);
			}
			else l[y][x]=l[x][y]=min(l[x][y],t);
		}
		floyd(l,n);
		floyd(s,n);
		ll r;
		cin>>r;
		vector<ll> z;
		for (ll i = 0; i < r; i++){
			ll t;
			cin>>t;
			z.push_back(t);
		}
		ve<ve<ll>> dp(r,ve<ll>(n+1,INF));
		dp[0][z[0]]=0;
		for (ll i = 1; i <= r-1; i++) {
			for (ll j = 1; j <= n; j++) {
				for (ll k = 1; k <= n; k++) {
					if(j==k)dp[i][j]=min(dp[i][j],dp[i-1][k]+l[z[i-1]][z[i]]);
					else dp[i][j]=min(dp[i][j],dp[i-1][k]+l[z[i-1]][k]+s[k][j]+l[j][z[i]]);
				}
			}
		}
		ll ret=INF;
		for(ll i=1;i<=n;i++)ret=min(ret,dp[r-1][i]);
		cout<<ret<<endl;
	}
	return 0;
}
