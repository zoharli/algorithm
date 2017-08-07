#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=-1000000;
#define N int(1e5+5)

int f[2*N],sum[2*N],n;

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i <= 200000; i++) {
		f[i]=sum[i]=INF;
	}
	f[100000]=sum[100000]=0;
	for (int i = 0; i < n; i++){
		int si,fi;
		cin>>si>>fi;
		if(si>=0){
			for(int j=200000;j>=0;j--){
				if(f[j]!=INF && f[j+si]<f[j]+fi){
					f[j+si]=f[j]+fi;
					sum[j+si]=sum[j]+si+fi;
				}
			}
		}
		else {
			for(int j=0;j<=200000;j++){
				if(f[j]!=INF && f[j+si]<f[j]+fi){
					f[j+si]=f[j]+fi;
					sum[j+si]=sum[j]+si+fi;
				}
			}
		}
	}
	int ret=0;
	for(int i=100000;i<=200000;i++){
		if(f[i]>=0)ret=max(ret,sum[i]);
	}
	cout<<ret<<endl;
	return 0;
}
