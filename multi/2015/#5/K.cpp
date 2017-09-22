/*************************************************************************
	> File Name: code/2015summer/#5/K.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 14时00分56秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1e2+5;
int b[N][N];
int n,m;
char cmd[505];
bool vis[N][N];
int nx,ny;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,-0,-1};
char ch[N][N];
int main()
{
    cin>>n>>m;
    nx = 0;
    ny = 0;
    for ( int i = 0 ; i < n ; i++)
	cin>>ch[i];
    for ( int i = 0 ; i <n ; i++ )
    {
	for ( int j = 0 ; j < m ; j++ )
	{
	    b[i+1][j+1]=(int)(ch[i][j]-'0');
	}
    }
    int ans  = 0;
    memset(vis,false,sizeof(vis));
    int dir = 1;
    cin>>cmd;
    int len = strlen(cmd);
    for ( int i = 0 ;  i < len ; i ++ )
    {
//	cout<<"ans:"<<ans<<endl;
//	cout<<"nx:"<<nx<<" ny:"<<ny<<endl;
	if (cmd[i]=='L')
	{
	    dir = (dir+3)%4;
	}
	if (cmd[i]=='R')
	{
	    dir  = (dir+1)%4;
	}
	if (cmd[i]=='M')
	{
	    if (dir==0)
	    {
		if (vis[nx][ny])
		{
		    ans = ans + b[nx][ny]/2;
		}
		else
		{
		    ans = ans + b[nx][ny];
		}
		if (vis[nx][ny+1])
		{
		    ans = ans + b[nx][ny+1]/2;
		}
		else
		{
		    ans = ans + b[nx][ny+1];
		}
		vis[nx][ny]=true;
		vis[nx][ny+1]=true;
		nx = nx +dx[dir];
		ny = ny +dy[dir];
	    }
	    if (dir==2)
	    {
		nx = nx + dx[dir];
		ny = ny + dy[dir];
		if (vis[nx][ny])
		{
		    ans = ans + b[nx][ny]/2;
		}
		else
		{
		    ans = ans + b[nx][ny];
		}
		if (vis[nx][ny+1])
		{
		    ans = ans + b[nx][ny+1]/2;
		}
		else
		{
		    ans = ans + b[nx][ny+1];
		}
		vis[nx][ny]=true;
		vis[nx][ny+1]=true;
	    }
	    if (dir==1)
	    {
		nx = nx + dx[dir];
		ny = ny + dy[dir];
		if (vis[nx][ny])
		{
		    ans = ans + b[nx][ny]/2;
		}
		else
		{
		    ans = ans + b[nx][ny];
		}
		if (vis[nx+1][ny])
		{
		    ans = ans + b[nx+1][ny]/2;
		}
		else
		{
		    ans = ans + b[nx+1][ny];
		}
		vis[nx][ny]=true;
		vis[nx+1][ny]=true;
		
	    }
            if (dir==3)
	    {
		
		if (vis[nx][ny])
		{
		    ans = ans + b[nx][ny]/2;
		}
		else
		{
		    ans = ans + b[nx][ny];
		}
		if (vis[nx+1][ny])
		{
		    ans = ans + b[nx+1][ny]/2;
		}
		else
		{
		    ans = ans + b[nx+1][ny];
		}
		vis[nx][ny]=true;
		vis[nx+1][ny]=true;
		nx = nx +dx[dir];
		ny = ny +dy[dir];
	    }
	}

    }
    cout<<ans<<endl;
  
	return 0;
}
