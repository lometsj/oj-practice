#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int f[20005];
int a[32];
int n,v;
int main()
{
    scanf("%d",&v);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=a[i];j--)
        f[j]=max(f[j],f[j-a[i]]+a[i]);
    }
    
    printf("%d",v-f[v]);
    while(1);
}
