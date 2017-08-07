#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	string s,t;
	cin>>s>>t;
	int q;
	cin>>q;
	vector<int> sa(1,0),sb(sa),ta(sa),tb(sa);
	for (int i = 0; i < s.size(); i++) {
		sa.push_back((s[i]=='A')+sa.back());
		sb.push_back((s[i]=='B')+sb.back());
	}
	for (int i = 0; i < t.size(); i++) {
		ta.push_back((t[i]=='A')+ta.back());
		tb.push_back((t[i]=='B')+tb.back());
	}
	for (int i = 0; i < q; i++) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ns,nt;
		nt=(ta[d]-ta[c-1]+(tb[d]-tb[c-1])*2)%3;
		ns=(sa[b]-sa[a-1]+(sb[b]-sb[a-1])*2)%3;
		if(nt==ns)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
