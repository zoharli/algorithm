#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N 500005


ll n,k;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	int ret;
	if((n/k)%2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
