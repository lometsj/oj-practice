#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int f[10010];

int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	else return f[x]=find(f[x]);
}

void hebin(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	f[fx]=fy;
	return;
}
struct node
{
	int u,v,w;
}a[10010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int n,m;

int scc=0;
int ans=0;
int main()
{
	freopen("prim.in","r",stdin);
    freopen("prim.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=a[i].u,y=a[i].v,w=a[i].w;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy)
		{
			ans+=w;
			hebin(x,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
