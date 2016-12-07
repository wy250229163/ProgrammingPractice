#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void markRoof(int (*a)[10],int (*tempa)[10],int i,int j,int n,int m,int *flag)
{
	if(tempa[i][j]==1)
		*flag=1;
	tempa[i][j]=1;
	if(j+1<=m-1 && a[i][j+1]==1)
		markRoof(a,tempa,i,j+1,m,n,flag);
	if(i+1<=n-1 && a[i+1][j]==1)
		markRoof(a,tempa,i+1,j,m,n,flag);
}
int Sum(int (*grid)[10],int n,int m)
{
//	static int tempgrid[10][10];
	int tempgrid[10][10];
	memset(tempgrid,0,sizeof(tempgrid));
	int i,j,flag=0;
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(grid[i][j]==1&&tempgrid[i][j]==0)
			{
				markRoof(grid,tempgrid,i,j,n,m,&flag);				
				sum++;
				if(flag==1)
				{
					sum--;
					flag=0;
				}
			}
		}
	}
	return sum;	
}
int main()
{
//	int i,j;
	int n=10,m=10;
	int grid[10][10]={
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,1,0,1},
						{0,0,0,1,1,1,1,1,1,1}};
//	scanf("%d%d",&n,&m);
//	for(i=0;i<n;i++)
//		for(j=0;j<m;j++)
//			scanf("%d",&grid[i][j]);
	printf("%d\n",Sum(grid,n,m));
	return 0; 
}

