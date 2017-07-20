#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	m+=1;
	for(int i=1;i<=n;i++)
	{
		m*=2;
	}
	printf("%d\n",m);
	return 0;
}
