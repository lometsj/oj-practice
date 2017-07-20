/*
	Name: ÎÚ¹êÆå 
	Copyright: walauview
	Author: lometsj
	Date: 03-11-13 19:08
	Description: hello world
*/
#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int a[1000];
int f[100][100][100][100]={0};
int b[5];

int max(int x,int y,int z,int a)
{
	int max=-1000;
	if(x>max)max=x;
	if(y>max)max=y;
	if(z>max)max=z;
	if(a>max)max=a;
	return max;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int t;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		b[t]++;
	}
	f[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)
	for(int j=0;j<=b[2];j++)
	for(int k=0;k<=b[3];k++)
	for(int q=0;q<=b[4];q++)
	{
		if(i==j && j==k && k==q && q==0)continue;
		int t1=0,t2=0,t3=0,t4=0;
		if(i-1>=0)t1=f[i-1][j][k][q];
		if(j-1>=0)t2=f[i][j-1][k][q];
		if(k-1>=0)t3=f[i][j][k-1][q];
		if(q-1>=0)t4=f[i][j][k][q-1];
		f[i][j][k][q]=max(t1,t2,t3,t4)+a[i+j*2+k*3+q*4+1];
	}
	printf("%d\n",f[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}
