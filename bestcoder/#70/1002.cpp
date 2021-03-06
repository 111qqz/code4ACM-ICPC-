/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 18时52分39秒
File Name :code/bc/#70/1002.cpp
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
const int N = 1E2+7;
const int M = 2E3+7;
int dp[M];
int w[N];
void ZeroOnePack( int cost,int value)
{
    for (int v = V ; i >= cost ; i--)
	f[v]=max(f[v],f[v-cost]+value);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    ms(dp,0x3f);
	    dp[0]=0;
	    cout<<"dp[1]:"<<dp[1]<<endl;

	    scanf("%d",&n);
	    for ( int i = 1 ;i  <= n ;i++) scanf("%d",&w[i]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
