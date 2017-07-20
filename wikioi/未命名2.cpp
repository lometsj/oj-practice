
#include<iostream>
 using namespace std;
 int dx[8]={-2,-1,1,2,2,1,-1,-2};
 int dy[8]={1,2,2,1,-1,-2,-2,-1};
 int f[20][20];
 int i,j,n,m,x,y,g[21][21];
int main()
 {
  //freopen("ghz.in","r",stdin);
  //freopen("ghz.out","w",stdout);
  cin>>n>>m>>x>>y;
  g[x][y]=1;//封锁马的位置
  for(i=0;i<8;i++)
     {
    int xx=x+dx[i],yy=y+dy[i];//定义马的控制点
    if(xx>=0 && xx<=n && yy>=0 && yy<=m)//判断是否出界
      g[xx][yy]=1;//封锁马的控制点
    }
  f[0][0]=1;//递推的初值
  for(i=1;i<=n;i++)
     if(g[i][0]==0)
       f[i][0]=f[i-1][0];
  for(i=1;i<=m;i++)
     if(g[0][i]==0)
       f[0][i]=f[0][i-1];//进行初始化
  for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
        if(g[i][j]==0)
          f[i][j]=f[i-1][j]+f[i][j-1];//动态转移
  cout<<f[n][m]<<endl;//打印输出
  return 0;
}

