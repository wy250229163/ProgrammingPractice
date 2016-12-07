#include<stdio.h>
void InsertionSort(int A[],int N)
{
	int j,p;
	int temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1]>temp;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 

int main()
{
	int s,i;
	int w,n;
	scanf("%d",&s);
	while(s--)
	{
		scanf("%d%d",&w,&n);
		int weight[n];
		int pI,pJ,counts=0;
		for(i=0;i<n;i++)
			scanf("%d",&weight[i]);
		InsertionSort(weight,n);
		pI=0;pJ=n;
		while(weight[--pJ]>=w) counts++;
//		printf("%d%d",pJ,counts); //ต๗สิ 
		while(pI<=pJ)
		{
			if(weight[pI]+weight[pJ]<=w)
			{
				counts++;pI++;pJ--; 
			}
			else
			{
				counts++;pJ--;
				if(pI==pJ)
				{
					counts++;break;
				}
			}
		}
		printf("%d\n",counts);
	}
}
 