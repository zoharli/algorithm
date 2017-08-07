#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
#define f(x) x=!x;
const int INF=0x3f3f3f3f;
#define N int(5e5+5)

int a[21],b[21];

int main(){
	ios::sync_with_stdio(false);
	for (int i = 0; i < 20; i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int c1=0,c2=1;
	f(b[0]);
	f(b[1]);
	for(int i=1;i<20;i++){
		if(a[i-1]){
			f(a[i-1]);
			f(a[i]);
			f(a[i+1]);
			c1++;
		}
		if(b[i-1]){
			f(b[i-1]);
			f(b[i]);
			f(b[i+1]);
			c2++;
		}
	}
	int ret=100;
	if(a[19]==0)ret=min(ret,c1);
	if(b[19]==0)ret=min(ret,c2);
	cout<<ret<<endl;
	return 0;
}
