#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	
		int x,step=0;
		scanf("%d",&x);
		while(x!=1)
		{
			if(x%2==1)x=3*x+1;
			else x/=2;
			step++;
		}
		printf("%d\n",step);
	}
	return 0;
}
