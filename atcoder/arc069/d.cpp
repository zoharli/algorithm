#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
string solve(char begin,char end){
	string ret;
	char last=end,cur=begin;
	for (int i = 0; i < n; i++) {
		char next;
		if(last=='S'){
			if(cur=='S'){
				if(s[i]=='o')next='S';
				else next='W';
			}
			else{
				if(s[i]=='o')next='W';
				else next='S';
			}
		}
		else {
			if(cur=='S'){
				if(s[i]=='o')next='W';
				else next='S';
			}
			else {
				if(s[i]=='o')next='S';
				else next='W';
			}
		}
		last=cur;
		cur=next;
		ret+=next;
	}
	if(ret[ret.size()-1]!=begin || ret[ret.size()-2]!=end)return "";
	else {
		return ret.back()+ret.substr(0,ret.size()-1);
	}
}

int main(void)
{
	cin>>n;
	cin>>s;
    string ret;
	if((ret=solve('S','S'))!=""){
		cout<<ret<<endl;
	}
	else if((ret=solve('S','W'))!=""){
		cout<<ret<<endl;
	}
	else if((ret=solve('W','W'))!=""){
		cout<<ret<<endl;
	}
	else if((ret=solve('W','S'))!=""){
		cout<<ret<<endl;
	}
	else cout<<-1<<endl;
	return 0;
}
