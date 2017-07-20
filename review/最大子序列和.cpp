#include <cstdio>
#include <iostream>
using namespace std;

int a[10010];
int b[10010];

int main()
{
	freopen("最大子序列和.in","r",stdin);
    freopen("最大子序列和.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(b[i-1]>0)b[i]=b[i-1]+a[i];
		else b[i]=a[i];
	}
	int maxa=-1;
	for(int i=1;i<=n;i++)
	{
		maxa=max(b[i],maxa);
	}
	printf("%d",maxa);
	return 0;
}
