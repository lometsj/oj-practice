#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char a[550];
char b[550];
char c[550];
int q=0;

int main()
{
	scanf("%s %s",a,b);
	int ok=1;
	int alen=strlen(a);
	int blen=strlen(b);
	
	for(int i=0;i<alen;i++)
	{
		a[i]-=48;
	}
	for(int i=0;i<blen;i++)
	{
		b[i]-=48;
	}

	if(alen==blen)
	{
		for(int i=0;i<=alen;i++)
		{
			if(a[i]>b[i])
			{
				ok=1;
				break;
			}
			if(a[i]==b[i])
			{
				continue;
			}
			if(a[i]<b[i])
			{
				ok=0;
				break;
			}
		}
	}
	
	
	if((blen>alen) || ok==0)
	{
		for(int i=blen-1;i>=0;i--)
		{
			char t=a[i];
			a[i]=b[i];
			b[i]=t;
		}
		ok=0;
	}
	
	if(ok==0)
	{
		int tt=alen;
		alen=blen;
		blen=tt;
	}
	
	if(alen>blen)
	
	for(int i=0;i<alen;i++)printf("%d",a[i]);
	printf("\n");
	for(int i=0;i<blen;i++)printf("%d",b[i]);
	printf("\n");
	
	for(int i=alen-1;i>=0;i--)
	{
		if(a[i]<b[i])
		{
			for(int j=i-1;j>=0;j--)
			{
				if(a[j]!=0)
				{
					a[j]-=1;
					if(a[j]==0)
					{
						q++;
					}
					for(int k=j+1;k<=i;k++)
					{
						if(k==i)
						{
							a[k]+=10;
						}
						else
						{
							a[k]=9;
						}
					}
					break;
				}
			}
		}
		if(a[i]>=b[i])
		{
			c[i]=a[i]-b[i];
			printf("%d-%d=%d\n",a[i],b[i],c[i]);
			
		}
	}
	if(!ok)
	{
		printf("-");
	}
	int see=1;
	for(int i=q;i<alen;i++)
	{
		if(c[i]!=0)see=0;
		if(!see)printf("%d",c[i]);
	}
	printf("\n");
	return 0;
}
