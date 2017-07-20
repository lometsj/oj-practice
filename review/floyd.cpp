#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int a[5000][5000];

int main()
{
	freopen("floyd.in","r",stdin);
    freopen("floyd.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		a[i][j]=1000000000;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	if(a[1][n]==1000000000)printf("NO\n");
	else printf("%d\n",a[1][n]);
	return 0;
}
