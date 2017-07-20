#include<stdio.h>
void transfer(int m,int change)
{ 
  int aa[20],j,saveM=m;
  for(j=0;m!=0;j++)
  {
    aa[j]=m%change;
    m=m/change;
   }
  printf("十进制数%d的%d进制形式是:\n",saveM,change);
  for(;j!=0;j--)
    printf("%d ",aa[j-1]); //注意这空是填aa[j-1]，而不是aa[j]，因为上面那个循环进行到最后一步时，j++还是会运行一次，但是此时并没有给aa[j]赋值，因为循环结束
}
main()
{
 int n,c;
 printf("请输入一个整数\n");
 scanf("%d",&n);
 printf("该整数是十进制数，你想将它转化成几进制数呢？\n");
 getchar();
 scanf("%d",&c);
 transfer(n,c);
}


