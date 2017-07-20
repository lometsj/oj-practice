#include <cstdio>
using namespace std;


int p;
int k;
int a[150];
int dp[150][150];

void read()
{
     scanf("%d",&p);
    //printf("%d",p);
     for(int i=1;i<=p;i++)
     {
             char x,y,stack;
             int a1,a2,z;
             scanf("%c %c %d\n",&x,&y,&z);
            // printf("%c %c %d\n",x,y,z);
             
             if(x==y)continue;
             if(x>='A'&&x<'Z')a[x]=1;
             if(dp[x][y]>z)dp[x][y]=dp[y][x]=z;

     }
     
}

void pre()
{
     for(int i=1;i<=123;i++)
     for(int j=1;j<=123;j++)
     {
             a[i]=1000000000;
             dp[i][j]=1000000000;
     }
}

void work()
{
     for(k=1;k<=123;k++)
     for(int i=1;i<=123;i++)
     for(int j=1;j<=123;j++)
     {
             if(i==j)continue;
             if(dp[i][j]>dp[i][k]+dp[k][j])
             {
                dp[i][j]=dp[i][k]+dp[k][j];
             }
     }
     int ans1=1000000000;
     char ans2=-1;
     for(int i=1;i<=123;i++)
     {
             if(dp[i]['Z']<ans1 && a[i]==1)
             {
                ans1=dp[i]['Z'];
                ans2=i;
             }
     }
     printf("%c %d\n",ans2,ans1);
}

int main()
{
    pre();
    read();
    work();
    while(1);
}
