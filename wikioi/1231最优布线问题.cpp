#include<cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long ans=0;
int n,m;
struct edge
{
	int s,t,w;
}a[100010];
int fa[100010];

int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}

bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].s,&a[i].t,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].s);
		int fy=find(a[i].t);
		if(fx!=fy)
		{
			ans+=a[i].w;
			fa[fx]=fy;
		}
	}
	cout<<ans<<endl;
	return 0;
}  
