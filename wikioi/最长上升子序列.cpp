#include <cstdio>
#include <iostream>

using namespace std;

int f[10000];

int main()
{
    int n;
    int a[10000];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        if(a[j]<a[i] && j<i)
        f[i]=max(f[i],f[j]+1);
    }
    printf("%d",f[n]+1);
    while(1);
}
