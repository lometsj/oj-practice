#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int ans=0;
int n,m;
int a[100][100];
int vis[100];

bool check(int x,int color)
{
    for(int i=1;i<=n;i++)
    {
        if(x==i) continue;
        if(!a[x][i]) continue;
        if(vis[i]==color) return false;
    }
    return true;
}

void dfs(int x)
{
	if(x>n)
	{
		ans++;
		return;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			if(check(x,i))
			{
				vis[x]=1;
				dfs(x+1);
				vis[x]=0;
			}
		}
	}
}

int main()
{
	freopen("深搜回溯法.in","r",stdin);
    freopen("深搜回溯法.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=1;
		a[v][u]=1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
