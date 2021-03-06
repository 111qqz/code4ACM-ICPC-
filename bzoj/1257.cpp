/* ***********************************************
Author :111qqz
Created Time :2016年11月28日 星期一 20时53分24秒
File Name :code/bzoj/1257.cpp
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
int main()
{
#ifndef  ONLINE_JUDGE 
    //	freopen("code/in.txt","r",stdin);
#endif
    LL n,k;
    LL ans = 0 ;
    scanf("%lld%lld",&n,&k);
    LL l,r,cur;
    r = n;
    cur = k/n;
    while (r)
    {
	l = k/(cur+1) + 1;
	ans += (l+r)*(r-l+1)/2 * cur;
	r = l-1;
	if (r==0) break;
	cur = k/r;
    }
    printf("%lld\n",k*n-ans);




#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
