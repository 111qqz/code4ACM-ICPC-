/* ***********************************************
Author :111qqz
Created Time :2016年04月22日 星期五 19时16分42秒
File Name :code/bc/#81/1002.cpp
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
const int N=1E3+7;
int a[N][N];
int px[N],py[N];
int row[N];
int col[N];
int n,m,q;

bool cmp( int x,int y)
{
    if (row[x]==row[y]) return col[x]<col[y];
    else return row[x]<row[y];
}

void print()
{
    for ( int i = 1 ;i <= n ; i++)
    {
	for ( int j = 1 ; j <= m-1 ; j++)
	{
	    printf("%d ",a[row[i]][col[j]]+px[row[i]]+py[col[j]]);
	}
	printf("%d\n",a[row[i]][col[m]]+px[row[i]]+py[col[m]]);
    }
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
	    scanf("%d %d %d",&n,&m,&q);
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		    scanf("%d",&a[i][j]);

	    for ( int i = 1 ; i <= n ; i++) row[i] = i;
	    for ( int i = 1 ; i <= m ; i++) col[i] = i;
	    ms(px,0);
	    ms(py,0);
	    while (q--)
	    {
		int opt;
		int x,y;
		scanf("%d %d %d",&opt,&x,&y);
		if (opt==1)
		{
		    swap(row[x],row[y]);
		}
		if (opt==2)
		{
		    swap(col[x],col[y]);
		}
		if (opt==3)
		{
		    px[row[x]]+=y;
		}
		if (opt==4)
		{
		    py[col[x]]+=y;
		}

	//	print();
	//	cout<<"opt:"<<opt<<" x:"<<x<<" y:"<<y<<endl;
	    }

	 //   sort(a+1,a+n*m+1,cmp);

	    print();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
