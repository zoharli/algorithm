#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,ne=0,no=0;
	cin>>n;
	for (int i = 0; i < n; i++) {
		int t;
		cin>>t;
		if(t%2)no++;
		else ne++;
	}
	ne+=no/2;
	no%=2;
	while(ne>1){
		ne=ne-ne/2;
	}
	if(ne+no==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}
