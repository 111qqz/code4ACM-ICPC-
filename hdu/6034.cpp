/* ***********************************************
Author :111qqz
Created Time :2017年11月01日 星期三 00时56分26秒
File Name :6034.cpp
************************************************ */

#include <bits/stdc++.h>
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
const int N=1E5+7;
const LL mod =1E9+7;
int n;
string st[N];
int cnt[26][N];
int maxlen;
int id[26];
int power[26];
LL base26[N];
bool Beg[26];
void init()
{
    ms(Beg,false);
    ms(cnt,0);
    maxlen = 0 ;
    for ( int i = 0 ; i < 26 ; i++) id[i] = i;
}
bool small(int *a,int *b)
{
    for ( int i = maxlen-1 ; i >= 0 ; i--)
    {
	if (a[i]<b[i]) return true;
	if (a[i]>b[i]) return false;
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int cas = 0 ;
	base26[0] = 1;
	for ( int i = 1 ; i < N ; i++) base26[i] = base26[i-1] * 26 % mod; 
	while (~scanf("%d",&n))
	{
	    init();
	    for ( int i = 1 ; i <= n ; i++) 
	    {
		cin>>st[i];
		int len = st[i].length();
	//	cout<<"len:"<<len<<endl;
		maxlen = max(len,maxlen);
		for ( int j = 0 ; j < len ; j++)
		{
		    int v = st[i][j]-'a';
		    cnt[v][len-j-1]++;
		}
		Beg[st[i][0]-'a'] = true;
		//忘了不能右前导0的条件了。。。
	    }
	    for ( int i = 0 ; i < 26 ; i++)
	    {
		for ( int j = 0 ; j < maxlen ; j++)
		{
		    cnt[i][j+1] += cnt[i][j]/26;
		    cnt[i][j]%=26;
		}
		while (cnt[i][maxlen]>0)
		{
		    cnt[i][maxlen+1] += cnt[i][maxlen]/26;
		    cnt[i][maxlen]%=26;
		    maxlen++;
		}
	    }

	    for ( int i = 0 ; i < 26 ; i++)
		for ( int j = i+1 ; j < 26 ; j++)
		    if (small(cnt[id[i]],cnt[id[j]]))
			swap(id[i],id[j]);
	for (int i = 0 ; i < 26 ; i++) printf("id[%d]:%c%c",i,char(id[i]+'a'),i==25?'\n':'\n');
	    if (Beg[id[25]])
	    {
		for ( int i = 24 ;  i >= 0 ; i--)
		{
		    if (!Beg[id[i]])
		    {
			swap(id[25],id[i]);
			break;
		    }
		}
	    }
	    for ( int i = 0 ; i < 26 ; i++) printf("id[%d]:%c\n",i,char(id[i]+'a'));

	    for ( int i = 0 ; i < 26 ; i++) power[id[i]] = 25-i;
	    LL ans = 0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int len = st[i].length();
		for ( int j = 0 ; j < len ; j++)
		{
		    int pos = len-j-1;
		    int v = st[i][j]-'a';
		    LL tmp = (base26[pos]*power[v])%mod;
		    ans = (ans + tmp)%mod;
		}
	    }
	    printf("Case #%d: %lld\n",++cas,ans);
		    
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
