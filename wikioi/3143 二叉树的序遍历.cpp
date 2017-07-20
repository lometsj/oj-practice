#include <cstdio>
#include <iostream>
using namespace std;

int a[100][3];

void qian(int x)
{
	printf("%d ",x);
	if(a[x][1]!=0)qian(a[x][1]);
	if(a[x][2]!=0)qian(a[x][2]);
}

void zhong(int x)
{
	if(a[x][1]!=0)zhong(a[x][1]);
	printf("%d ",x);
	if(a[x][2]!=0)zhong(a[x][2]);
}

void hou(int x)
{
	if(a[x][1]!=0)hou(a[x][1]);
	if(a[x][2]!=0)hou(a[x][2]);
	printf("%d ",x);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][1],&a[i][2]);
	}
	qian(1);
	printf("\n");
	zhong(1);
	printf("\n");
	hou(1);
	printf("\n");
	return 0;
}
