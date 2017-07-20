#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int ans=1000000000;
int d[300][300];
int a[300][300];
int n,m;

int main()
{
	freopen("floyd最小环.in","r",stdin);
    freopen("floyd最小环.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(d,0x07,sizeof(d));
    memset(a,0x07,sizeof(a));
	/*for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		d[i][j]=1000000000;
		a[i][j]=1000000000;
	}*/
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
		d[u][v]=w;
		d[v][u]=w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		for(int j=i+1;j<k;j++)
		{
			ans=min(ans,d[i][j]+a[i][k]+a[k][j]);
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	if(ans==1000000000)
	{
		printf("He will never come back.\n");
	} 
	else
	{
		printf("%d\n",ans);
	}
	return 0;
}
