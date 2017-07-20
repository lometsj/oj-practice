#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	/*int t=n%m,tt=n/m;;
	char a;
	a='A';
	if(t>=10)
	{
		t-=10;
		a+=t;
		printf("%d%c",tt,a);
		return 0;
	}
	if(n>=m)t+=n/m;
	printf("%d%d",tt,t);*/
	int t,tt;
	int a[255];
	int k=0;
	t=n%m;
	tt=n/m;
	a[k++]=t;
	while(tt!=0)
	{
		n=tt;
		t=n%m;
		tt=n/m;
		a[k++]=t; 
	} 
	for(int i=k-1;i>=0;i--)
	{
		char b='A';
		if(a[i]>=10)printf("%c",b+a[i]-10);
		else printf("%d",a[i]);
	}
	return 0;
}
