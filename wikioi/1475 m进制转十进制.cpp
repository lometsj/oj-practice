#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int b=0,n;
	char a[255];
	scanf("%s %d",a,&n);
	int len=strlen(a);
	int c=1;
	for(int i=len-1;i>=0;i--)
	{
		if(a[i]>='0' && a[i]<='9')b+=((a[i]-48)*c);
		else b+=((a[i]-55)*c);
		c*=n;
	}
	printf("%d",b);
	return 0;
}
