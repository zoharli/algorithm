#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
const int INF=0x3f3f3f3f;
#define N 2500

int C,L;
vector<pair<int,int>> c,l;

int main(){
	ios::sync_with_stdio(false);
	cin>>C>>L;
	for (int i = 0; i < C; i++){
		int a,b;
		cin>>a>>b;
		c.push_back({a,b});
	}
	for (int i = 0; i < L; i++){
		int a,b;
		cin>>a>>b;
		l.push_back({a,b});
	}
	sort(c.begin(),c.end());
	sort(l.begin(),l.end());
	priority_queue<int,vector<int>,greater<int>> q;
	int i=0;
	int ret=0;
	for(auto x:l){
		while(i<c.size()&&c[i].fi<=x.fi){
			q.push(c[i].se);
			i++;
		}
		while(q.size() && q.top()<x.fi)q.pop();
		while(x.se && q.size()){
			q.pop();
			ret++;
			x.se--;
		}
	}
	cout<<ret<<endl;
	return 0;
}
