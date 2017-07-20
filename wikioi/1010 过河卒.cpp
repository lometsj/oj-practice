#include <cstdio>
#include <iostream>

using namespace std;

int dx[9]={0,1,-1,2,-2,1,-1,2,-2};
int dy[9]={0,2,2,1,1,-2,-2,-1,-1};
bool vis[20][20];
int f[30][30];
int n,m;
int x,y;
int main()
{
	
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<=8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<=n && ny<=m)
		{
			vis[nx][ny]=1;
			//printf("%d %d\n",nx,ny);
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i][0]==0)f[i][0]=f[i-1][0];
	}
	
	for(int j=1;j<=m;j++)
	{
		if(vis[0][j]==0)f[0][j]=f[0][j-1];
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(vis[i][j]==0)f[i][j]=f[i-1][j]+f[i][j-1];
	}
	printf("%d",f[n][m]);
	return 0;
}
