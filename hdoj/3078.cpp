/* ***********************************************
Author :111qqz
Created Time :2017年07月31日 星期一 01时12分54秒
File Name :3078.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PB push_back
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=8E4+7;
int n,q;
int val[N];
vector < pi > edge[N];
int in[N];
int E[2*N],R[2*N],dis[N],depth[2*N];
int p;
int fa[N];
int dp[2*N][20];
void dfs( int u,int dep,int d,int pre)
{

    //  cout<<"u:"<<u<<" dep:"<<dep<<" d:"<<d<<endl;
    fa[u] = pre;
    p++;
    E[p] = u;
    depth[p] = dep;
    R[u] = p ;
    dis[u] = d;


    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
        int v = edge[u][i].fst;
        if (v==pre) continue;
        dfs(v,dep+1,d+edge[u][i].sec,u);

        p++;
        E[p] = u;
        depth[p] = dep;
    }
}



int _min( int l,int r)
{
    if (depth[l]<depth[r]) return l;
    return r;
}
void rmq_init()
{
    for ( int i = 1 ; i <= 2*n+2 ; i++) dp[i][0] = i;

    for ( int j = 1 ; (1<<j) <= 2*n+2 ; j++)
        for ( int i = 1 ; i + (1<<j)-1 <= 2*n+2 ; i++)
            dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_min( int l,int r)
{
    if (l>r) swap(l,r);
    int k = 0 ;
    while (1<<(k+1)<=r-l+1) k++;
    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int D(int u,int v) //计算u,v点的距离
{
    int LCA = E[rmq_min(R[u],R[v])];
    int res = dis[u] + dis[v] - 2*dis[LCA];
    return res;
}
void get_path(vector<int> &v,int s,int t)
{
    while (s!=t)
    {
	v.PB(val[s]);
	s = fa[s];
    }
}
bool cmp(int a ,int b){return a>b;}
void solve(int k,int u,int v)
{
    int LCA = E[rmq_min(R[u],R[v])];
    vector<int>path;
    get_path(path,u,LCA);
    get_path(path,v,LCA);
    path.PB(val[LCA]);
    sort(path.begin(),path.end(),cmp);
    int siz = path.size();
 //   for ( int i = 0 ; i < siz ; i++) printf("%d ",path[i]);
 //   printf("\n");
    if (k>siz)
    {
	puts("invalid request!");
	return;
    }
    printf("%d\n",path[k-1]);
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&q))
	{
	    ms(val,0);
	    for ( int i = 1 ;i <= n ; i++) scanf("%d",&val[i]);
	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].PB(MP(v,1));
		edge[v].PB(MP(u,1));
	    }
	    p = 0 ;
	    dfs(1,0,0,-1);
	    rmq_init();
	    while (q--)
	    {
		int k,u,v;
		scanf("%d%d%d",&k,&u,&v);
		if (k==0)
		{
		    val[u] = v;
		}
		else 
		{
		    solve(k,u,v);
		}
	    }
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
