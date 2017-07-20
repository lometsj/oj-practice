//by:lometsj
#include <cstdio>
#include <iostream>

int n;
int c[100];
int v;
bool f[120];

int main()
{
	freopen("装箱问题.in","r",stdin);
    freopen("装箱问题.out","w",stdout);
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=v;j>=c[i];j--)
	{
		if(f[j-c[i]])
		{
			f[j]=1;
		}
	} 
	int ans;
	for(int i=v;i>=0;i--)
	{
		if(f[i])
		{
			printf("%d",v-i);
			return 0;
		}
	}
}
