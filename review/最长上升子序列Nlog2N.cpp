//by:lometsj
#include <cstdio>
#include <iostream>
using namespace std;

int f[20010];
int a[20010];
int main()
{
	freopen("最长上升子序列Nlog2N.in","r",stdin);
    freopen("最长上升子序列Nlog2N.out","w",stdout);
	int n;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=-1;
	for(int i=2;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j] && f[j]+1>f[i])
			{
				f[i]=f[j]+1;
			}
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
} 
