#include <cstdio>
#include <iostream>

using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    int a[106];
    int s[106];
    int dp[106][106];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    s[0]=a[0];
    for(int i=1;i<n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
    }
    for(int v=1;v<n;v++)
    for(int i=0;i<n-v;i++)
    {
        int j=i+v;
        dp[i][j]=1000000000;
        int add=s[j]-(i>0 ? s[i-1]:0);
        for(int k=i;k<j;k++)
        {
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+add);
        }
    }
    printf("%d",dp[0][n-1]);
    while(1);
}
