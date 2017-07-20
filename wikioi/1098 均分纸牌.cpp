#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int ans=0;
	int sub=0;
	int n;
	int a[120];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sub+=a[i];
	}
	int dn=sub/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==dn)continue;
		a[i+1]+=a[i]-dn;
		if(a[i+1]==dn)
		{
			i++;
		}
		ans++;
	}
	printf("%d\n",ans);
	//while(1);
	return 0;
}
