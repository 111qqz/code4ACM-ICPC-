/* ***********************************************
Author :111qqz
Created Time :2017年11月08日 星期三 18时50分18秒
File Name :3518.cpp
************************************************ */

//#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
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
#define MAXALP 55 //还有大写字母orz
int k;
struct state
{
	int len, link, nxt[MAXALP];
};
const int N =1E5+7;
state st[N*2];
int sz, last,rt;
char s[N];
int Right[2*N];
int cnt[2*N],rk[2*N];//for radix sort
int dp[2*N],lazy[2*N];
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
}
void sa_extend(int c)
{
	int cur = ++sz;
	st[cur].len = st[last].len + 1;
	memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
	int p;
	for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
		st[p].nxt[c] = cur;
	if (p == -1) {
		st[cur].link = rt;
	} else {
		int q = st[p].nxt[c];
		if (st[p].len + 1 == st[q].len) {
			st[cur].link = q;
		} else {
			int clone = ++sz ;
			st[clone].len = st[p].len + 1;
			st[clone].link = st[q].link;
			memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
			for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
				st[p].nxt[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
void topo()
{
	ms(cnt,0); 
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
	for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
}
char ST[N];
int idx( char c)
{
    if (c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    	freopen("./in.txt","r",stdin);
#endif
    while (~scanf("%d",&k)!=EOF)
    {
	if (k==0) break;
	ms(Right,0);
	ms(lazy,0); //parent树上的lazy标记，最后子底向上更新
	scanf("%s",ST);
//	cout<<"ST:"<<ST<<endl;
	sa_init();
	for (int i = 0,len = strlen(ST);  i < len ; i++)
	{
	    Right[sz+1] = 1;
	    sa_extend(idx(ST[i]));
	}
	topo();
	for ( int i = sz ; i >=1 ; i--) if (st[rk[i]].link!=-1)Right[st[rk[i]].link]+=Right[rk[i]];
	//check right
//	for ( int i = sz ; i >=1 ; i--) printf("right:%d\n",Right[i]);
	scanf("%s",ST);
	int now = rt,len = 0;
	LL ans = 0 ;
	for ( int i = 0,_len = strlen(ST) ; i < _len ; i++)
	{
	    int id = idx(ST[i]);
	    if (st[now].nxt[id]!=-1)
	    {
		now = st[now].nxt[id];
		len++;
		//  printf("now:%d dp[now]:%d len: %d\n",now,dp[now],len);
	    }
	    else 
	    {
		while (now!=-1&&st[now].nxt[id]==-1) now = st[now].link;
		if (now==-1) now=rt,len=0;else len = st[now].len + 1,now=st[now].nxt[id];
	    }
//	    printf("len:%d\n",len);
	    if (len>=k)
	    {
		if (st[now].link==-1) continue;
		ans += 1LL*(len-max(k,st[st[now].link].len+1)+1)*Right[now];
		if (st[st[now].link].len>=k) lazy[st[now].link]++;
	    }
	}

	for ( int i = sz ; i >= 1 ; i-- )
	{
	    int v = rk[i];
	    if (st[v].link==-1) continue;
	    ans += 1LL*lazy[v]*(st[v].len-max(k,st[st[v].link].len+1)+1)*Right[v];
	    if (st[st[v].link].len>=k) lazy[st[v].link] += lazy[v]; //lazy标记沿着parent树向上传递
	}
	printf("%lld\n",ans);
    }





#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}

