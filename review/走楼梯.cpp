//by:lometsj

#include <cstdio>
#include <iostream>
using namespace std;


int f(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else if(n==2)
	{
		return 2;
	}
	else if(n==3)
	{
		return 4;
	}
	else
	{
		return f(n-1)+f(n-2)+f(n-3);
	}
}

int main()
{
	freopen("×ßÂ¥ÌÝ.in","r",stdin);
    freopen("×ßÂ¥ÌÝ.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ans=f(n);
	printf("%d\n",ans);
	return 0;
}
