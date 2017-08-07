#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N 500005


int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		vector<pair<int,int>> a;
		set<int> s;
		cin>>n;
		for (int i = 0; i < n; i++){
			int l,w;
			cin>>l>>w;
			a.push_back({l,w});
		}
		sort(a.begin(),a.end());
		set<int>::iterator it;
		for(auto x:a){
			if((it=s.upper_bound(x.se))!=s.begin()){
				s.erase(--it);
			}
			s.insert(x.se);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}
