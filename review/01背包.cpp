//by:lometsj
#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int c[105];
int r[105];
int dp[100000];
int ans=0;
int main()
{
	freopen("01교관.in","r",stdin);
    freopen("01교관.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&c[i],&r[i]);
        r[i]=r[i]*c[i];
    }
    for(int i=1;i<=n;i++)
    for(int j=m;j>=c[i];j--)
    {
        //for(int k=0;k*c[i]<=m;k++)
        //{
            //dp[i][j]=max(dp[i][j],dp[i-1][j-k*c[i]]+k*r[i]);
            //}
        dp[j]=max(dp[j],dp[j-c[i]]+r[i]);
    }
    //for(int j=0;j<=m;j++)ans=max(ans,dp[n][j]);
    printf("%d",dp[m]);
    /*for (int i=1;i<=n;i++)
{
for (int j=c[i];j<=m;j++)
{
dp[j]=max(dp[j],dp[j-c[i]]+r[i]);
}
}
printf("%d\n",dp[m]+m);*/
   // while(1);
}


