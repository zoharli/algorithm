#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	string a,b;
	cin>>a>>b;
	int la=a.size(),lb=b.size();
	int ans;
	if (a==b) {
		ans=-1;
	}
	else {
		ans=max(la,lb);
	}
	cout << ans << endl;
	
	return 0;
}
