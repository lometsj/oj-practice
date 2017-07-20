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

bool cha(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)return 0;
	else return 1;
}

int n,m,p;

int main()
{
	freopen("并查集.in","r",stdin);
    freopen("并查集.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		hebin(x,y);
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int ok=cha(x,y);
		if(ok)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
