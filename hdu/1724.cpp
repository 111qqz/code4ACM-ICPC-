/* ***********************************************
Author :111qqz
Created Time :2017年10月09日 星期一 21时09分36秒
File Name :1724.cpp
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
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
double a,b,l,r;
double dblcmp(double d){ return d<-eps?-1:d>eps;}
double f(double x)
{
    double ret;
    ret = sqrt((1-(x*x/a/a))*b*b);
    return ret;
}
double simpson(double l,double r)
{
    return (r-l)*(f(l) + f(r) + 4*f((l+r)*0.5))/6;
}
double di( double l,double r)
{
    //cout<<"l:"<<l<<" r:"<<r<<endl;
    double m = (l+r)*0.5;
    double ans = simpson(l,r);
    if (dblcmp(ans-simpson(l,m)-simpson(m,r))==0) return ans;
    return di(l,m) + di(m,r);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lf %lf %lf %lf",&a,&b,&l,&r);
	    double ans = di (l,r)*2.0;
	    printf("%.3f\n",ans);
	}

	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
