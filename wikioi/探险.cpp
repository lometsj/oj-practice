#include <cstdio>
#include <iostream>

using namespace std;

int n,k;
int a[100010];

bool check(int x);
void ef(int l,int r);

int main()
{
    scanf("%d%d",&n,&k);
    int xiao=1000000000,da=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        xiao=min(xiao,a[i]);
        da+=a[i];
    }
    ef(xiao,da);
    while(1);
    return 0;
}


bool check(int x)
{
    int scc=0,t=0;
    for(int i=1;i<=n;i++)
    {
        t+=a[i];
        if(t>=x)
        {
            t=0;
            scc++;
        }
    }
    return scc>=k;
}

void ef(int l,int r)
{
    while(r>l)
    {
        int m=(l+r)/2;
        if(check(m+1))l=m+1;
        else r=m;
    }
    printf("%d",l);
}
