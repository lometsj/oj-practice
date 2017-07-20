#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        int q=sqrt(x)+0.5;
        for(int j=2;j<=q;j++)
        {
            if(x%j==0)
            {
                ans++;
                break;
            }
        }
    }
    printf("%d",n-ans);
    while(1);
}
