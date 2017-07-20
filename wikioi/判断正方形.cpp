#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int s,t,ok=1;
    scanf("%d",&s);
    for(int i=1;i<=3;i++)
    {
        scanf("%d",&t);
        if(s!=t)
        ok=0;
    }
    if(ok)printf("Yes");
    else printf("No");
    while(1);
}
