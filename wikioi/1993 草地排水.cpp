#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int a[220];
int c[220][220];
int ans=0;
int step[220];
int f[220][220];

int dfs(int x);

int main()
{
	queue<int>q;
	scanf("%d%d",&m,&n);
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		c[x][y]=z;
	}
	while(1)
	{
		for(int i=1;i<=n;i++)a[i]=0;
		a[1]=200000000;
		q.push(1);
		
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=1;i<=n;i++)
			{
				if(!a[i] && c[u][i]>f[u][i])
				{
					step[i]=u;q.push(i);
					a[i]=min(a[u],c[u][i]-f[u][i]);
				}
			}
		}
		
		if(a[n]==0)break;
		for(int i=n;i!=1;i=step[i])
		{
			f[step[i]][i]+=a[n];
			f[i][step[i]]-=a[n];
		}
		ans+=a[n];
	}
	printf("%d\n",ans);
	return 0;
	
}
