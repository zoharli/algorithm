#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define H 800

int vis[H][H];
char a[H][H];
int h,w,k;
int u,d,l,r;

bool check(int x,int y,int k){
	if(x>=0 && x<h && y>=0 && k>=1 && y<w && a[x][y]!='#' && !vis[x][y])return true;
	return false;
}

int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void dfs(int x,int y,int k){
	queue<pair<int,int>> que;
	queue<int> kque;
	que.push({x,y});
	vis[x][y]=1;
	kque.push(k);
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		k=kque.front();
		que.pop();
		kque.pop();
		u=min(x,u);
		d=max(x,d);
		l=min(l,y);
		r=max(r,y);
		for (int i = 0; i < 4; i++) {
			if(check(x+dx[i],y+dy[i],k)){
				que.push({x+dx[i],y+dy[i]});
				vis[x+dx[i]][y+dy[i]]=1;
				kque.push(k-1);
			}
		}
	}
}

int main(void)
{
	cin>>h>>w>>k;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>a[i][j];
			if(a[i][j]=='S'){
				u=d=i;
				l=r=j;
			}
		}
	}
	dfs(u,l,k);
	int dmin=min(u-0,min(h-1-d,min(l-0,w-1-r)));
	cout<<ceil(float(dmin)/k)+1<<endl;
	return 0;
}
