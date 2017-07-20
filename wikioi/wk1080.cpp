#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[100000+10];
int n,m;

struct Tree
{
    int left,right;
    int sum;
}tree[100000*4+10];

void build(int id,int l,int r)
{
     tree[id].left=l;
     tree[id].right=r;
     if(l==r)
     {
        tree[id].sum=a[l];
     }
     else
     {
         int mid=(l+r)/2;
         build(id*2,l,mid);
         build(id*2+1,mid+1,r);
         tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
     }
}

void update(int id,int pos,int val)
{
     int l=tree[id].left,r=tree[id].right;
     if(l==r)     
     {
         tree[id].sum+=val;
     }
     else
     {
         int mid=(l+r)/2;
         if(pos<=mid)update(id*2,pos,val);
         else update(id*2+1,pos,val);
         tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
     }
}

int qsum(int id,int a,int b)
{
     int l=tree[id].left,r=tree[id].right;
     if(l==a&&r==b)
     {
         return tree[id].sum;
     }
     else
     {
         int mid=(l+r)/2;
         if(b<=mid)return qsum(id*2,a,b);
         else if(a>mid)return qsum(id*2+1,a,b);
         else return qsum(id*2,a,mid)+qsum(id*2+1,mid+1,b);
     }
}

void work()
{
     int k,b,c;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)scanf("%d",&a[i]);
     build(1,1,n);
     scanf("%d",&m);
     for(int i=1;i<=m;i++)
     {
         scanf("%d%d%d",&k,&b,&c);
         if(k==1)update(1,b,c);
         else printf("%d\n",qsum(1,b,c));
     }
}

int main()
{
    work();
    return 0;
}
