#include<stdio.h>
int result=0; //�����
int main()
{
 int a[9][9];
 void Sudoku(int a[9][9],int n);
 printf("�����������е�ԭʼ���ݣ�û�����ݵ���0���档\n");
 for(int i=0;i<9;i++)
 {
  printf("�������%d�е�9������",i+1);
  for(int j=0;j<9;j++)
   scanf("%d",&a[i][j]);
 }
 printf("�����Ľ�Ϊ��\n\n");
 Sudoku(a,0);
 if(result==0)
  printf("�������޽�!");
 return 0;
}
//������еĽ�
void print(int a[9][9])
{
 result++;
 printf("��%d���Ϊ��\n",result);
 for(int i=0;i<9;i++)
 {
  for(int j=0;j<9;j++)
  {
   printf("%d ",a[i][j]);
   if((j==2)||(j==5))
    printf(" ");
  }
  printf("\n");
  if((i==2)||(i==5))
   printf("\n");
 }
 printf("\n");
}
//�ж��Ƿ���Խ���i�С���j�е�����Ϊk
bool check(int a[9][9],int i,int j,int k)
{
 int m,n;
 //�ж���
 for(n=0;n<9;n++)
 {
  if(a[i][n] == k)
   return false;
 }
 //�ж���
 for(m=0;m<9;m++)
 {
  if(a[m][j] == k)
   return false;
 }
 //�ж�����С�Ź���
 int t1=(i/3)*3,t2=(j/3)*3;
 for(m=t1;m<t1+3;m++)
 {
  for(n=t2;n<t2+3;n++)
  {
   if(a[m][n] == k)
    return false;
  }
 }
 //���У�����true
 return true;
}
//������⺯��
void Sudoku(int a[9][9],int n)
{
 int temp[9][9];
 int i,j;
 for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
   temp[i][j]=a[i][j];
 }
 i=n/9; j=n%9; //�����n����������������
 if(a[i][j] != 0) //�Ѿ���ԭʼ����
 {
  if(n == 80)   //�����һ�����ӣ�������н�
   print(temp);
  else    //�������һ�����ӣ�����һ������
   Sudoku(temp,n+1);
 }
 else    //û������
 {
  for(int k=1;k<=9;k++)
  {
   bool flag=check(temp,i,j,k);
   if(flag) //��i�С���j�п�����k
   {
    temp[i][j]=k; //��Ϊk
    if(n == 80)
     print(temp);
    else
     Sudoku(temp,n+1);
    temp[i][j]=0; //�ָ�Ϊ0���ж���һ��k
   }
  }
 }
}
 
