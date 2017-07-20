
//欧几里德辗转相除 

//递归形式 
int gcd(int a,int b)
{

if(b==0) return a;
else  return gcd(b,a%b);
}


//迭代形式 1   ---->    避免堆栈的浪费 

int gcd(int a,int b)  //最大公约数 
{
        int t;
        while(b！=0)
       {   t=a;
           a=b;
           b=t%b;       
          }
return a;
}



//迭代形式 2

int gcd(int x,int y)  //最大公约数 
{
        if(!x||!y)return x>y?x:y;
        for (int t;t=x%y;x=y,y=t)
        ;
            return y;
            }




//快速gcd   二进制思想 
int kgcd(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if (!(a&1)&&!(b&1))  return kgcd(a>>1,b>>1)<<1;
      
    else if (!(b&1)) return kgcd(a,b>>1);
    else if (!(a&1)) return kgcd(a>>1,b);
    else return kgcd(abs(a-b),min(a,b));
    }




//扩展 欧几里德gcd
int  extgcd(int a,int b,int &x,int &y)
{
     if(b==0)
     {x=1; y=0;
     return a;}
     else
     { 
     int d=extgcd(b,a%b,x,y);
     int t=x,x=y,y=t-a/b*y;
     return d;
     }
     } 
     
     
     //筛选素数【1....n】 
     bool  is[N];int prm[M];
     int getprm(int n)
     {
         int i,j,k=0;
         int s,e=(int)(sqrt(0.0+n)+1);
         memset(is,1,sizeof(is));
         prm[k++]=i;
         for (i=4;i<n;i+=2) is[i]=0;  //4以上的偶数为合数
         for(i=3;i<e;i+=2)  //3以上的奇数
         {
                   if(is[i])
                  prm[K++]=i;
                  for(s=i*2,j=i*i;j<n;j+=s)
                  is[j]=0;
                  //因为j是奇数，再加上奇数，是偶数，不必处理！ 
                  }
         
         for(;i<n;i+=2) if(is[i]) prm[k++]=i; 
         return k;   //返回素数的个数 
         }  
         
   


      
   //高效求小范围的素数 
   int prime[500],mum,boo[2500];
   for(i=2;i<=2300;i++) boo[i]=0

   for(i=2;i<=50;i++)
    for(k=2*i;K<=2300;k=k+i)
   boo[k]=1;       //去掉合数（小数的是这些的倍数）

   int nmu=0;
   for(int i=2;i<=2300;i++)
   if(boo[i]==0) prime[num++]=i;
            
 

                       
//随机素数测试（伪素数原理）

//调用的时候 
bool res=miller(n);
//对任意的奇数n>2,和正整数s，出错概率<=2^(-s) 

int witness(int a,int n)
{
    int x,d=1,i=ceil(log(n-1.0)/log(2.0))-1;
    for(;i>=0;i--)
    {x=d;d=(d*d)%n;
    if(d==1&& x!=1 && x!n-1) return 1;
    if(((n-1)&(1<<i))>0)d=(d*a)%n;
}
return (d==1?0:1);
     }


int miller(int n,int s=50)
{
    if(n==2) return 1;
    if(n%2==0) return 0;
    int j,a;
    for(j=0;j<s;j++)
    {
 a=rand()*(n-2)/RAND_MAX+1;
 if(witness(a,n)) return 0;
}
 return 1; 
    }






 
