//by:lometsj

#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int c[1000];
int r[1000];
int dp[100000];

int main()
{
	freopen("完全背包.in","r",stdin);
    freopen("完全背包.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&r[i]);
    }
    for(int i=1;i<=n;i++)
    for(int j=c[i];j<=m;j++)
    {
        dp[j]=max(dp[j],dp[j-c[i]]+r[i]);
    }
    int ans=dp[m];
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    
    printf("%d",ans);
    return 0;
}

