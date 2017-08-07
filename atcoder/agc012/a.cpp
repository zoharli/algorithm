#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005

ll sum,n;
vector<int> a;

int main(void)
{
	cin>>n;
	a.resize(3*n);
	for (int i = 0; i < 3*n; i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	for (int i = 0; i < n; i++) {
		sum+=a[2*i+1];
	}
	cout<<sum<<endl;
	return 0;
}
