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
#define N int(1e5+5)

struct T{
	P l,r,m;
};
struct node{
	T t;
	int l,r;
};

int a[N],n,q;
node seg[2*N];

T merge(T t1,T t2){
	T ret;
	if(t1.r.se==t2.l.se){
		P k={t1.r.fi+t2.l.fi,t1.r.se};
		ret.m=max(t1.m,max(t2.m,k));
		ret.l=t1.l.se==t1.r.se?k:t1.l;
		ret.r=t2.l.se==t2.r.se?k:t2.r;
	}
	else {
		ret.m=max(t1.m,t2.m);
		ret.l=t1.l;
		ret.r=t2.r;
	}
	return ret;
}
T build(int v,int l,int r){
	seg[v].l=l;
	seg[v].r=r;
	if(l==r){
		return seg[v].t=T{{1,a[l]},{1,a[l]},{1,a[l]}};
	}
	else {
		int mid=(l+r)/2;
		T t1=build(2*v,l,mid),t2=build(2*v+1,mid+1,r);
		return seg[v].t=merge(t1,t2);
	}
}

T query(int v,int l,int r){
	if(l==seg[v].l && r==seg[v].r)return seg[v].t;
	int mid=(seg[v].l+seg[v].r)/2;
	if(l>mid)return query(2*v+1,l,r);
	if(r<=mid)return query(2*v,l,r);
	return merge(query(2*v,l,mid),query(2*v+1,mid+1,r));
}


int main(){
	ios::sync_with_stdio(false);
	while(1){
		cin>>n;
		if(!n)return 0;
		cin>>q;
		for (int i = 1; i <= n; i++) {
			cin>>a[i];
		}
		build(1,1,n);
		for (int i = 0; i < q; i++){
			int l,r;
			cin>>l>>r;
			T t=query(1,l,r);
			cout<<max(t.l,max(t.r,t.m)).fi<<endl;
		}
	}
	return 0;
}
