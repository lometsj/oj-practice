#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int ans=0;
    int d=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x>d)
        {
            ans+=(x-d)*6+5;
            d=x;
        }
        if(x<d)
        {
            ans+=(d-x)*4+5;
            d=x;
        }
    }
    printf("%d",ans);
    while(1);
}
