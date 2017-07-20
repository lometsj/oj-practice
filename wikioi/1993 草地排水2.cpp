#include <cstdio>
#include <iostream>
#define maxn 220
using namespace std;

int m,n,ans,c[maxn][maxn],d[maxn],cur[maxn];
int q[maxn],l,r;
bool bfs()
{
	for(int i=1;i<=n;i++)d[i]=-1;
	
	l=0,r=0;
	d[1]=0;//start into que;
	q[r++]=1;
	while(l<r)
	{
		int i=q[l++];
		for(int j=1;j<=n;j++)
		{
			if(d[j]==-1 && c[i][j]>0)
			{
				d[j]=d[i]+1;
				if(j==n)return 1;
				q[r++]=j;
			}
		}
	}
	
	return 0;
}

int dfs(int i,int low)
{
	
	//printf("%d %d \n",i,low);
	if(i==n)return low;
//	if(low==0)return low;
	
	int res;
	for(int &j=cur[i];j<=n;j++)
	{
		if ( (c[i][j]>0) && (d[j]==d[i]+1) && (res=(dfs(j,min(low,c[i][j])))))
		{
			c[i][j]-=res;
			c[j][i]+=res;
			return res;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&m,&n);
	int x,y,cap;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&cap);
		c[x][y]+=cap;
	}
	
	while(bfs())
	{
		for(int i=1;i<=n;i++)cur[i]=1;
		while(int res=dfs(1,0x3f3f3f3f))ans+=res;
	}
	printf("%d\n",ans);
	//while(1);
}
