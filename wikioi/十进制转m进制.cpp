#include<stdio.h>
void transfer(int m,int change)
{ 
  int aa[20],j,saveM=m;
  for(j=0;m!=0;j++)
  {
    aa[j]=m%change;
    m=m/change;
   }
  printf("ʮ������%d��%d������ʽ��:\n",saveM,change);
  for(;j!=0;j--)
    printf("%d ",aa[j-1]); //ע���������aa[j-1]��������aa[j]����Ϊ�����Ǹ�ѭ�����е����һ��ʱ��j++���ǻ�����һ�Σ����Ǵ�ʱ��û�и�aa[j]��ֵ����Ϊѭ������
}
main()
{
 int n,c;
 printf("������һ������\n");
 scanf("%d",&n);
 printf("��������ʮ�����������뽫��ת���ɼ��������أ�\n");
 getchar();
 scanf("%d",&c);
 transfer(n,c);
}


