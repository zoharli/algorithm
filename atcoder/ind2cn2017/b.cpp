#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,m;
vector<int> perm;
unordered_map<int,unordered_map<int,int>> val;
int cal(){
	int ret=0;
	for(int i=0;i<k-1;i++){
		for (int j = i+1; j < k; j++) {
			ret+=val[perm[i]][perm[j]]+val[perm[i+k]][perm[j+k]];
		}
	}
	return ret;
}
void permutate(int i,int &ret){
	if(i==perm.size()){
		ret=max(ret,cal());
		return;
	}
	for(int j=i;j<perm.size();j++){
		swap(perm[i],perm[j]);
		permutate(i+1,ret);
		swap(perm[i],perm[j]);
	}
}

int solve(){
	int ret=0;
	perm.resize(n);
	for (int i = 1; i <= n; i++){
		perm[i-1]=i;
	}
	permutate(0,ret);
	return ret;
}

int main(void)
{
	cin>>n>>k>>m;
	for (int i = 0; i < m; i++) {
		int a,b,u;
		cin>>a>>b>>u;
		val[a][b]=val[b][a]=u;
	}
	cout<<solve()<<endl;
	return 0;
}
