#include<stdio.h>

int lis(int *A,int n)
{
	int d[n];
	int i,j;
	int tmpmax=1;
	for(i=0;i<n;i++)
	{
		d[i]=1;
		for(j=0;j<i;j++)
		{
			if(A[j]<A[i] && d[j]+1>d[i])  //此步同时找出了最大值d[i] 
				d[i]=d[j]+1;
		}
		if(d[i]>tmpmax)
			tmpmax=d[i];
	}
	return tmpmax;
} 

int main()
{
	int len;
	int A[]={5,3,4,8,6,7};
	len=lis(A,6);
	printf("%d\n",len);
}