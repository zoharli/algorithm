#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h,w,a,b;
char raw[100][100];

int main(void)
{
	cin>>h>>w>>a>>b;
	for (int i = 0; i < h; i++) {	
		for (int j = 0; j < w; j++) {
			cin>>raw[i][j];
		}
	}
	for (int i = 0; i < h*a; i++) {
		for (int j = 0; j < w*b; j++) {
			cout<<raw[i%h][j%w];
		}
		cout<<endl;
	}

	return 0;
}
