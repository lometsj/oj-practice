#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
struct node
{
	int x,n,w;
}a[20000000];

bool vis[2000000];
int f[2000000];
int d[2000000];
int scc=0;

int main()
{
	freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=-1;
		d[i]=1000000000;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		scc++;
		a[scc].w=w;
		a[scc].x=v;
		a[scc].n=f[u];
		f[u]=scc;
		scc++;
		a[scc].w=w;
		a[scc].x=u;
		a[scc].n=f[v];
		f[v]=scc;
	}
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		int min=1000000000,x;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i] && d[i]<min)
			{
				min=d[i];
				x=i;
			}
		}
		vis[x]=1;
		for(int e=f[x];e!=-1;e=a[e].n)
		{
			if(d[a[e].x]>d[x]+a[e].w)
			{
				//printf("?\n");
				d[a[e].x]=d[x]+a[e].w;
			}
		}
	}
	if(d[n]==1000000000)
	{
		printf("NO\n");
	}
	else
	{
		printf("%d\n",d[n]);
	}
	return 0;
}
