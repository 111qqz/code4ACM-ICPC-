/* ***********************************************
Author :111qqz
Created Time :2016年02月18日 星期四 14时32分29秒
File Name :code/cf/problem/373C.cpp
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
const int N=5E5+7;
int a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

	sort(a+1,a+n+1);
	
	int j = n;
	int ans = 0 ;
	for (int  i = n/2 ;  i >=1 ; i--)
	{
	    if (a[j]>=2*a[i])
	    {
		ans++;
		j--;
	    }
	}
	cout<<n-ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
