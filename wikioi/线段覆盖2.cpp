/*
	Name: Ïß¶Î¸²¸Ç2 
	Copyright: walauview
	Author: lometsj
	Date: 03-11-13 19:42
	Description: hello pig
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int s,t,w;
}a[1500];
int n;

bool cmp(node a,node b)
{
	if(a.t==b.t)
	{
		return a.w>b.w;
	}
	else return a.t<b.t;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].s,&a[i].t,&a[i].w);
	sort(a+1,a+1+n,cmp);
	int x=-1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].s>x)
		{
			x=a[i].s;
			ans+=a[i].w;
		}
	}
	printf("%d\n",ans);
	return 0;
}
