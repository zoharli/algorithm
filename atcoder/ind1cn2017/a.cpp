#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> b(n,vector<int>(n,0));
	b[0][0]=1;
	int i=0,j=0;
	int d=0;
	for(int k=0;k<m-1;k++){
		if(d==0){
			if(j<n-1 && b[i][j+1]==0){
				j+=1;
			}
			else {
				d=1;
				i++;
			}
		}
		else if(d==1){
			if(i<n-1 && b[i+1][j]==0){
				i++;
			}
			else {
				d++;
				j--;
			}
		}
		else if(d==2){
			if(j>0 && b[i][j-1]==0){
				j--;
			}
			else {
				d++;
				i--;
			}
		}
		else {
			if(i>0 && b[i-1][j]==0){
				i--;
			}
			else {
				d=0;
				j++;
			}
		}
		b[i][j]=1;
	}
	cout<<i+1<<' '<<j+1<<endl;
	return 0;
}
