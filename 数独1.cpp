#include<stdio.h>
int result=0; //结果数
int main()
{
 int a[9][9];
 void Sudoku(int a[9][9],int n);
 printf("请输入数独中的原始数据，没有数据的用0代替。\n");
 for(int i=0;i<9;i++)
 {
  printf("请输入第%d行的9个数：",i+1);
  for(int j=0;j<9;j++)
   scanf("%d",&a[i][j]);
 }
 printf("数独的解为：\n\n");
 Sudoku(a,0);
 if(result==0)
  printf("此数独无解!");
 return 0;
}
//输出可行的解
void print(int a[9][9])
{
 result++;
 printf("第%d个填法为：\n",result);
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
//判断是否可以将第i行、第j列的数设为k
bool check(int a[9][9],int i,int j,int k)
{
 int m,n;
 //判断行
 for(n=0;n<9;n++)
 {
  if(a[i][n] == k)
   return false;
 }
 //判断列
 for(m=0;m<9;m++)
 {
  if(a[m][j] == k)
   return false;
 }
 //判断所在小九宫格
 int t1=(i/3)*3,t2=(j/3)*3;
 for(m=t1;m<t1+3;m++)
 {
  for(n=t2;n<t2+3;n++)
  {
   if(a[m][n] == k)
    return false;
  }
 }
 //可行，返回true
 return true;
}
//数独求解函数
void Sudoku(int a[9][9],int n)
{
 int temp[9][9];
 int i,j;
 for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
   temp[i][j]=a[i][j];
 }
 i=n/9; j=n%9; //求出第n个数的行数和列数
 if(a[i][j] != 0) //已经有原始数据
 {
  if(n == 80)   //是最后一个格子，输出可行解
   print(temp);
  else    //不是最后一个格子，求下一个格子
   Sudoku(temp,n+1);
 }
 else    //没有数据
 {
  for(int k=1;k<=9;k++)
  {
   bool flag=check(temp,i,j,k);
   if(flag) //第i行、第j列可以是k
   {
    temp[i][j]=k; //设为k
    if(n == 80)
     print(temp);
    else
     Sudoku(temp,n+1);
    temp[i][j]=0; //恢复为0，判断下一个k
   }
  }
 }
}
 
