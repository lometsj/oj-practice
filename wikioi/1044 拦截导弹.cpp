/*
	Name: µ¼µ¯À¹½Ø 
	Copyright: walauview
	Author: lometsj
	Date: 03-11-13 20:33
	Description: hello sigma
*/
#include <cstdio>
#include <iostream>
using namespace std;
int n;
int a[30];
int b[30];
int f[30];


int main()
{
	int scc=1;
	while(scanf("%d",&a[scc++])!=EOF);
	int ans=1;
	for(int i=1;i<scc;i++)f[i]=1;
	for(int i=2;i<scc;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]<=a[j] && f[i]<f[j]+1)f[i]=f[j]+1;
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<scc;i++)f[i]=1;
	ans=1;
	for(int i=2;i<scc;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j] && f[i]<f[j]+1)f[i]=f[j]+1;
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
