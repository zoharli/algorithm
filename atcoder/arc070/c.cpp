#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x;
int main(void)
{
	cin>>x;
	int i=0;
	while(1){
		x-=(1+i);
		i++;
		if(x<=0)break;
	}
	cout<<i<<endl;
	return 0;
}
