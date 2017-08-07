#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=0x3f3f3f3f;
#define N 500005
#define in(x) (x>='a'&&x<='z')

map<char,int> good;
string p;

int main(){
	ios::sync_with_stdio(false);
	string t;
	cin>>t;
	for(auto x:t)good[x]=1;
	cin>>p;
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int i=0,j=0;
		while(j<s.size()&&i<p.size()){
			if(p[i]!=s[j]){
				if(p[i]=='?'){
					if(!good[s[j]])break;
					i++;
					j++;
				}
				else if(p[i]=='*'){
					int l1,l2;
					l1=p.size()-1-i;
					l2=s.size()-l1;
					if(l2<j){
						break;
					}
					else if(l2>j){
						for(;j<l2;j++){
							if(good[s[j]])break;
						}
						if(j!=l2)break;
						i++;
					}
					else i++;
				}
				else break;
			}
			else {
				i++;
				j++;
			}
		}
		if(i==p.size()&&j==s.size())cout<<"YES"<<endl;
		else if(p.back()=='*'&&j==s.size()&&i==p.size()-1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
