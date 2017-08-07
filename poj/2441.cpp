#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define vec vector
const double eps=1e-6;
const int inf=0x3f3f3f3f;
#define N (1024*1024)

int c[N],dp[21][N],mask[21],n,m;

int solve(){
	int ret=0;
	for(int i=1;i<N;i++){
		int t=i;
		while(t){
			if(t&1)c[i]++;
			t>>=1;
		}
	}
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		int p;
		set<int> s;
		cin>>p;
		for (int i = 0; i < p; i++){
			int t;
			cin>>t;
			s.insert(t);
		}
		for(int x=1,y=1;x<=20;y<<=1,x++){
			if(s.count(x))mask[i]+=y;
		}
	}
	dp[0][0]=1;
	for (int i = 1; i <= n; i++) {
		for(int j=1;j<N;j++){
			if(c[j]!=i)continue;
			for(int x=1,y=1;x<=20;y<<=1,x++){
				if( (y&mask[i]) && (y&j)){
					dp[i][j]+=dp[i-1][y^j];
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		ret+=dp[n][i];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cout<<solve()<<endl;
	return 0;
}
