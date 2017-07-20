#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int b[100008];

struct xian
{
    int z,y,sum;
}a[100000*4+10];

void build(int i,int z,int y)
{
    a[i].z=z;
    a[i].y=y;
    if(z==y)
    {
        a[i].sum=b[z];
    }
    else
    {
        int m=(z+y)/2;
        build(i*2,z,m);
        build(i*2+1,m+1,y);
        a[i].sum=a[i*2].sum+a[i*2+1].sum;
    }
}

int cha(int i,int x)
{
    int z=a[i].z,y=a[i].y;
    if(z==y)
    {
        return a[i].sum;
    }
    else
    {
        int m=(z+y)/2;
        if(x<=m)return cha(i*2,x);
        else return cha(i*2+1,x);
    }
}

void jia(int i,int x,int val)
{
    int z=a[i].z,y=a[i].y;
    if(z==y)
    {
        a[i].sum+=val;
    }
    else
    {
        int m=(z+y)/2;
        if(x<=m)jia(i*2,x,val);
        else jia(i*2+1,x,val);
        a[i].sum=a[i*2].sum+a[i*2+1].sum;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)    scanf("%d",&b[i]);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            int x,y,xx;
            scanf("%d%d%d",&x,&y,&xx);
            for(int j=x;j<=y;j++)
            jia(1,j,xx);
        }
        else
        {
            int cc;
            scanf("%d",&cc);
            printf("%d\n",cha(1,cc));
        }
    }
    while(1);
}
