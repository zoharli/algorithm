//not completely right yet
//require double queue to fix it 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 100005
#define M 100005
int tot,head[N];
struct E{int next,to,d;E(int a=0,int b=0,int c=0):next(a),to(b),d(c){} }e[M<<1];
inline void add(int x,int y,int z=1){e[++tot]=E(head[x],y,z);head[x]=tot;}
int num[N],n,d[N],isleave[N];
vector<int> leave[N];
queue<int> que;
bool solve(){
	for (int i = 1; i <= n; i++){
		if(d[i]==1){
			que.push(i);
		}
	}
	int left=n;
	while(que.size()){
		int v=que.front();
		que.pop();
		ll sum=0;
		int maxnum=0;
		for(int i=0;i<leave[v].size();i++){
			int x=leave[v][i];
			sum+=x;
			maxnum=max(maxnum,x);
		}
		ll t=ceil(double(sum)/double(2));
		if(num[v]<maxnum||num[v]<t)return false;
		if(left==1){
			if(leave[v].size()==1&&num[v]>sum||leave[v].size()>1&&(sum%2||maxnum>sum/2||num[v]>sum/2))return false;
			else return true;
		}
		if(maxnum>t){
			num[v]-=(sum-maxnum);
		}
		else num[v]-=(sum/2);
		for(int i=head[v];i;i=e[i].next){
			if(!isleave[e[i].to])leave[e[i].to].push_back(num[v]);
			if(--d[e[i].to]==1)que.push(e[i].to);
		}
		isleave[v]=1;
		left--;
	}
	return true;
}
int main(void)
{
	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>num[i];
	}
	for (int i = 1; i < n; i++) {
		int a,b;
		cin>>a>>b;
		add(a,b);
		d[a]++;
		add(b,a);
		d[b]++;
	}
	if(solve())cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
