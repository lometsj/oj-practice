#include <cstdio>
#include <iostream>
using namespace std;
int maxf=-1,maxw=-1;
int f[100],w[100];


int main()
{
	int n;
	scanf("%d",&n);
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		f[a]=f[b]=f[i]+1;
	}
	for(int i=1;i<=n;i++)
	{
		maxf=max(maxf,f[i]);
		w[f[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		maxw=max(w[i],maxw);
	}
	printf("%d %d\n",maxw,maxf);
	return 0;
}

