#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct node 
{
	int s,t;
}a[120];

bool operator <(const node &a,const node &b)
{
	return a.t<b.t;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].s,&a[i].t);
		if(a[i].t<a[i].s)
		{
			int t=a[i].t;
			a[i].t=a[i].s;
			a[i].s=t;
		}
	}
	sort(a+1,a+1+n);
	int minn=-1000;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].s>=minn)
		{
			minn=a[i].t;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
