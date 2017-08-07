
#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define vec vector
const double eps=1e-6;
const int inf=0x3f3f3f3f;
#define N int(1e2+5)

int n,m,h[2*N],h1[2*N],prevv[2*N],preve[2*N];
struct E{
	int to,d,cap,rev;
	E(int a,int b,int c,int d):to(a),d(b),cap(c),rev(d){}
};

int main(){
	ios::sync_with_stdio(false);
	E e=E(1,2,3,4);
	cout<<e.rev<<endl;
	return 0;
}
