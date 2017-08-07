#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N int(1e3+5)
#define M int(1e5+5)

int n,m,x;
vec<pair<int,int> > a1[N],a2[N];

vec<int> dijkstra(vec<pair<int,int> > a[]){
	int cnt=1;
	vec<int> r(n+1,INF),s(n+1);
	r[x]=0;
	s[x]=1;
	priority_queue<pair<int,int>,vec<pair<int,int> >,greater<pair<int,int> > > q;
	for(int i=0;i<a[x].size();i++){
		pair<int,int> y=a[x][i];
		r[y.fi]=min(r[y.fi],y.se);
		q.push({y.se,y.fi});
	}
	while(cnt<n){
		while(s[q.top().se])q.pop();
		int to=q.top().se,d=q.top().fi;
		s[to]=1;
		for(int i=0;i<a[to].size();i++){
			pair<int,int> y=a[to][i];
			if(!s[y.fi] && r[y.fi]>d+y.se){
				r[y.fi]=d+y.se;
				q.push({d+y.se,y.fi});
			}
		}
		cnt++;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>x;
	for (int i = 0; i < m; i++){
		int a,b,t;
		cin>>a>>b>>t;
		a1[a].push_back({b,t});
		a2[b].push_back({a,t});
	}
	vec<int> r1,r2;
	r1=dijkstra(a1);
	r2=dijkstra(a2);
	int ret=0;
	for (int i = 1; i <= n; i++) {
		ret=max(ret,r1[i]+r2[i]);
	}
	cout<<ret<<endl;
	return 0;
}
