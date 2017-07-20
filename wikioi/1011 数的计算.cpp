#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
queue <int >q;

int ans=0;

void dfs(int x)
{
	if(x==1)
	{
		ans++;
		return;
	}
	else
	{
		ans++;
		for(int i=1;i<=x/2;i++)
		{
			dfs(i);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	dfs(n);
	printf("%d\n",ans);
	return 0;
}
