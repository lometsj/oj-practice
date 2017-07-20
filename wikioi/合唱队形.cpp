#include <cstdio>
#include <iostream>
using namespace std;
int n,a[105],b[105];
    int f1[105],f2[105];
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[n-i+1]=a[i];
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    for(int i=1;i<=n;i++){f1[i]=1;
    for(int j=1;j<=n;j++)
        if(a[i]>a[j] && i>j)f1[i]=max(f1[i],f1[j]+1);}
    for(int i=1;i<=n;i++){f2[i]=1;
    for(int j=1;j<=n;j++)
        if(b[j]<b[i] && j<i)f2[i]=max(f2[i],f2[j]+1);}
    int max1=-1;
    for(int i=1;i<=n;i++)
    {
        int cc=f1[i]+f2[n-i+1]-1;
        max1=max(max1,cc);
        printf("f1=%d f2=%d    \n",f1[i],f2[i],cc);
    }

    int ans;
    printf("%d\n",max1);
    ans=n-max1;
    printf("%d",ans);
    while(1);

}
