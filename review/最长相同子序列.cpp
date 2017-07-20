#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int dp[2010][2010];
char a[2010];
char b[2010];
int main()
{
	freopen("最长相同子序列.in","r",stdin);
    freopen("最长相同子序列.out","w",stdout);
	scanf("%s%s",a+1,b+1);
	int al=strlen(a+1);
	int bl=strlen(b+1);
	for(int i=1;i<=al;i++)
	for(int j=1;j<=bl;j++)
	{
		if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
		else 
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d",dp[al][bl]);
	return 0;
}
