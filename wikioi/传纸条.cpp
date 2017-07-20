#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int a[55][55];
int f[55][55][55][55];

int max(int a,int b,int c,int d)
{
	int maxx=-1;
	if(a>maxx)maxx=a;
	if(b>maxx)maxx=b;
	if(c>maxx)maxx=c;
	if(d>maxx)maxx=d;
	return maxx;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j]);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=1;k<=n;k++)
	{
		int l; 
		if(i+j-k>0)l=i+j-k;
		else continue;
		f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i][j-1][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
		if(i==k && j==l)f[i][j][k][l]-=a[i][j];
	}
	printf("%d\n",f[n][m][n][m]);
	return 0;
}
