#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int e=sqrt(n)+0.5;
    for(int i=2;i<=e;i++)
    {
        if(n%i==0)
        {
            printf("%d",n/i);
        }
    }
    return 0;
}
