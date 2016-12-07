#include<stdio.h>
#include<math.h>

void InsertionSort(double A[],int N)
{
	int j,p;
	double temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1]<temp;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 

int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int n,i,counts=0;
		double l=0;	
		double r[1000];
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&r[i]);
		InsertionSort(r,n);
		for(i=0;i<n;i++)
		{
			if(l<20.0&&r[i]>1)
			{
				l+=2*sqrt(r[i]*r[i]-1);
				counts++;
			}
		}
		printf("%d\n",counts);	
	}
}
 