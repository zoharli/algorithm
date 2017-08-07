#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin>>n;
	vector<int> a(26,100);
	for (int i = 0; i < n; i++) {
		string s;
		cin>>s;
		vector<int> cnt(26,0);
		for(auto x:s){
			cnt[x-'a']++;
		}
		for(int j=0;j<26;j++){
			a[j]=min(a[j],cnt[j]);
		}
	}
	string ret;
	int i=0;
	for(auto x:a){
		ret+=string(x,'a'+i);
		i++;
	}
	cout<<ret<<endl;
	return 0;
}
