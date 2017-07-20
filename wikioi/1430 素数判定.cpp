#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x;
	scanf("%d",&x);
	int n=sqrt(x);
	if(x==1 || x==0)return 0;
	for(int i=2;i<=n;i++)
	{
		if(x%i==0)
		{
			printf("\\n");
			return 0;
		}
	}
	printf("\\t");
	return 0;
}
