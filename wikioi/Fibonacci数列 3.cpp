#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a=1,b=1;
    if(n==1 || n==2)
    {printf("1");return 0;}
    for(int i=3;i<=n;i++)
    {
        int t=b;
        b=a+b;
        a=t;
        if(i==n)printf("%d",b);
    }
    while(1);
}
