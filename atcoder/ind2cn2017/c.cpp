#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h,w,d,r;
char a[11][11];
int vis[11][11],usedvis[11][11];

bool check(int x,int y,int u){
	if(x>=0 && y>=0 && x<h && y<w && a[x][y]!='#'){
		if(u && !usedvis[x][y])return true;
		else if(!u && !vis[x][y])return true;
	}
	return false;
}
int solve(int dx[],int dy[]){
	int k,x,y,u;
	queue<pair<int,int>> que;
	queue<int> step;
	queue<int> used;
	que.push({0,0});
	step.push(0);
	used.push(0);
	vis[0][0]=1;
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		k=step.front();
		u=used.front();
		que.pop();
		used.pop();
		step.pop();
		if(x==h-1&&y==w-1)return k;
		if(!u&& check(x+d,y+r,1)){
			que.push({x+d,y+r});
			step.push(k+1);
			used.push(1);
			usedvis[x+d][y+r]=1;
		}
		for (int i = 0; i < 4; i++) {
			if(check(x+dx[i],y+dy[i],u)){
				que.push({x+dx[i],y+dy[i]});
				used.push(u);
				step.push(k+1);
				if(u)usedvis[x+dx[i]][y+dy[i]]=1;
				else vis[x+dx[i]][y+dy[i]]=1;
			}
		}
	}
	return -1;
}

int main(void)
{
	cin>>h>>w>>d>>r;
	int dx[]={-1,0,1,0};
	int dy[]={0,-1,0,1};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>a[i][j];
		}
	}
	cout<<solve(dx,dy)<<endl;
	return 0;
}
