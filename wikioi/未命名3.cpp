#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct pp{
int x,y,p;
};
//记住有个冒号><

int e[20001],f[20001],n,m,i,j,k,t;
pp a[100001];

bool cmp(const struct pp &x,const struct pp &y){
return x.p>y.p;
}
//cmp的写法><.
int find(int x){
if (f[x]==x) return x;
f[x]=find(f[x]);
return f[x];
}

int main(){
cin>>n>>m;
for (i=1;i<=m;i++)
 cin>>a[i].x>>a[i].y>>a[i].p;
sort(a+1,a+1+m,cmp);
for (i=1;i<=n;i++)f[i]=i;

for (i=1;i<=m;i++){
if (find(a[i].x)==find(a[i].y)){
cout<<a[i].p<<endl; while(1);return 0;
}
if (e[a[i].y]!=0&&find(a[i].x)!=find(e[a[i].y]))
  f[find(a[i].x)]=find(e[a[i].y]);
  e[a[i].y]=a[i].x;

if (e[a[i].x]!=0&&find(a[i].y)!=find(e[a[i].x]))
  f[find(a[i].y)]=find(e[a[i].x]);
  e[a[i].x]=a[i].y;
}

 cout<<0<<endl;
  return 0;

}
