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

int cha(int i,int c,int d)
{
    int z=a[i].z,y=a[i].y;
    if(z==c && y==d)
    {
        return a[i].sum;
    }
    else
    {
        int m=(z+y)/2;
        if(d<=m)return cha(i*2,c,d);
        else if(c>=m+1)return cha(i*2+1,c,d);
        else return cha(i*2,c,m)+cha(i*2+1,m+1,d);
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
        int k,x,a;
        scanf("%d%d%d",&k,&x,&a);
        if(k==1)jia(1,x,a);
        else printf("%d\n",cha(1,x,a));
    }
    while(1);
}
