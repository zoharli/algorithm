#include <cmath>
#include <vector>
#include<iostream>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N 2050

int main(){
	ios::sync_with_stdio(false);
	int x;
	while(cin>>x){
		int i=0;
		int a[N],cnt[N],l[N];
		a[0]=cnt[0]=1;
		l[0]=0;
		int q=int(sqrt(x));
		int b[N];
		int j;
		for(j=1;j<=q;j++){
			if(x%j==0){
				a[i]=j;
				b[i++]=x/j;
			}
		}
		int s=2*i-1-(q*q==x);
		for(int k=0,j=s;j>=i;j--,k++){
			a[j]=b[k];
		}
		for(int i=1;i<=s;i++){
			l[i]=cnt[i]=0;
			for(int j=0;j<i;j++){
				if(a[i]%a[j]==0){
					l[i]=max(l[i],l[j]);
				}
			}
			for(int j=0;j<i;j++){
				if(a[i]%a[j]==0 && l[i]==l[j]){
					cnt[i]+=cnt[j];
				}
			}
			l[i]++;
		}
		cout<<l[s]<<' '<<cnt[s]<<endl;
	}
	return 0;
}
