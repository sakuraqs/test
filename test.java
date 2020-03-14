package mg;
import java.util.*;
public class test {	
	static int[][] maze;            //迷宫矩阵maze 	
	static int n;                   //矩阵规格
	static int min;                 //最短步长	
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in); //接收用户手动输入		
		n = sc.nextInt();		//输入矩阵大小(整数)
		min = n*n;		      //根据输入的n确定最短步长
		maze = new int[n][n];		
		for(int i=0;i<n;i++)			
			for(int j=0;j<n;j++) 				
				maze[i][j] = sc.nextInt();		//接收maze中每个i，j的值
		recursion(1, 1, 0);            //起始点为（1，1），初始步长为0		
		if(min==n*n)			
			System.out.println("No solution");		
		else 			
			System.out.println(min);	
		}	
	public static void recursion(int x, int y, int count) {		
		if(x==n-2 && y==n-2)             //跳出条件，走到[n-2][n-2]位置即为终点		
			min = Math.min(count, min);		
		else {			
			maze[x][y]=1;                 //走过的位置设为1		
			if(y<n-1 && maze[x][y+1]==0) {			
				recursion(x, y+1, count+1);			//右		
				}		
			if(x<n-1 && maze[x+1][y]==0) {			
				recursion(x+1, y, count+1);			//下			
				}			
			if(x>1 && maze[x-1][y]==0) {				
				recursion(x-1, y, count+1);			//上		
				}			
			if(y>1 && maze[x][y-1]==0) {				
					recursion(x, y-1, count+1);		//左		
					}			                        //回溯，			
				maze[x][y]=0;                          	
				
				}	
		}
	}

