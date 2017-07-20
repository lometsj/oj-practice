#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int s=a[1];
    int c=1;
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    for(int i=2;i<=n;i++)
    {
        if(s==a[i])
        {
            c++;
        }
        if(s!=a[i])
        {
            if(c%2==1)printf("%d",s);
            s=a[i];
            c=1;
        }
    }
    if(c%2==1)printf("%d",s);
    //while(1);

}
