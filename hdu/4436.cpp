/* ***********************************************
Author :111qqz
Created Time :2017年11月08日 星期三 18时50分18秒
File Name :4436.cpp
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
#define MAXALP 12
const int mod = 2012;
struct state
{
	int len, link, nxt[MAXALP];
};
const int N =1E5+7;
state st[N*2];
int sz, last,rt;
char s[N];
int cnt[2*N],rk[2*N];//for radix sort
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
    ms(cnt,0);
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
int num[2*N],dp[2*N]; //num[i]表示SAM上到达状态i的子串的数量。
//sum[i]表示SAM上到达状态i的答案。
int n;
int main()
{
#ifndef  ONLINE_JUDGE 
    	freopen("./in.txt","r",stdin);
#endif

    while (~scanf("%d",&n))
    {
	sa_init();

	ms(num,0);
	ms(dp,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%s",s+1);
	    int len_s = strlen(s+1);
	    for ( int i = 1 ; i <= len_s ; i++)
	    {
		sa_extend(s[i]-'0');
	    }
	    sa_extend(10); //插入一个没有出现的字符做分隔符
	}
	//  a simple radix sort
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
	for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;


	num[rt] = 1;
	for ( int i = 1 ; i <= sz ; i++)
	{
	    int u = rk[i];
//	    printf("u:%d\n",u);
	    for ( int j = 0 ;j < 10 ; j++)
	    {
		if (i==1&&j==0) continue;  //有前缀0不更新答案，也就是初始态的不转移到0. i==1时表示初始态
		int v = st[u].nxt[j];
		if (v==-1) continue;
		num[v] += num[u];
		dp[v] = dp[v] + (dp[u] * 10 ) + num[u] * j; //类似数位dp,u所表示的状态左移一位，所以dp[u]*10,
		//然后有num[u]个子串到达u，每个都可以转移j这条边，因此答案贡献是num[u]*j
		dp[v] %=mod;
	    }
	}
	int ans = 0 ;
	for ( int i = 1 ; i <= sz ; i++) ans = ( ans + dp[i])%mod;
	printf("%d\n",ans);
    }


#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
