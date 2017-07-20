#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[2500][2500];
int n,m;
bool vis[2500][2500];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
char cc[255];


void dfs(int x,int y)
{
	//printf("%d %d\n",x,y);
	for(int i=0;i<=4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1 && ny>=1 && nx<=n && ny<=m && vis[nx][ny]==0 && a[nx][ny]!=0)
		{
			vis[nx][ny]=1;
			dfs(nx,ny);
		}
	}	
}

int ans=0;
int main()
{
	freopen("遍历染色.in","r",stdin);
    freopen("遍历染色.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",cc+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=cc[j]-48;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(!vis[i][j] && a[i][j]!=0)
		{
			ans++;
			vis[i][j]=1;
			dfs(i,j);
		}
	}
	printf("%d\n",ans);
	return 0;
}
