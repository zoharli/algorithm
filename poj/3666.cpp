#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const ll INF=0x3f3f3f3f3f3f;
#define N int(2e3+5)

vector<int> a,b;
ll dp1[N][N],dp2[N][N];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	b=a;
	sort(b.begin(),b.end());
	for (int i = 1; i <= n; i++) {
		ll m1=INF,m2=INF;
		for (int k=n,j = 1; j <= n; j++,k--) {
			m1=min(m1,dp1[i-1][j]);
			dp1[i][j]=m1+abs(a[i-1]-b[j-1]);
			m2=min(m2,dp2[i-1][k]);
			dp2[i][k]=m2+abs(a[i-1]-b[k-1]);
		}
	}
	ll ret=INF;
	for (int i = 1; i <= n; i++) {
		ret=min(ret,min(dp1[n][i],dp2[n][i]));
	}
	cout<<ret<<endl;
	return 0;
}
