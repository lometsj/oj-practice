#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,f[20010],s[20010];
struct node
{int u,v,w;
friend bool operator > (node a,node b)
    {
        return a.w > b.w;
    }}a[100001];
    
int e[20010];
int k=1;
int find(int x);
void he(int x,int y);
bool cmp(node a,node b)
{
    return a.w > b.w;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    for(int i=1;i<=n;i++)
    {

    }
    sort(a+1,a+1+m,cmp);
    
    for(int i=1;i<=m;i++)
    {
        int x=a[i].u;
        int y=a[i].v;
        int fx=find(x);int fy=find(y);
        if(fx!=fy)
        {
            if(e[y]!=0 && fx!=find(e[y]))f[fx]=find(e[y]);
            e[y]=x;
            if(e[x]!=0 && fy!=find(e[x]))f[fy]=find(e[x]);
            e[x]=y;
        }
        if(fx==fy)
        {
            printf("%d",a[i].w);
            while(1);
        }
    }
    printf("0");
    while(1);
}

int find(int x)
{
    if(f[x]==x)return x;
    else  return f[x]=find(f[x]);
}

void he(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    f[fx]=fy;
}
