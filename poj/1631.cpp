#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N 500005

vector<int> a;
int p,T;

int find(int x){
	int i=0,j=a.size();
	while(i<j){
		int mid=(i+j)/2;
		if(a[mid]>x){
			j=mid;
		}
		else i=mid+1;
	}
	return i;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>p;
		a.clear();
		for (int i = 0; i < p; i++){
			int t;
			cin>>t;
			int x=find(t);
			if(x==a.size())a.push_back(t);
			else a[x]=t;
		}
		cout<<a.size()<<endl;
	}
	return 0;
}
