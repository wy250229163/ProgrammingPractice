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
void dealarray(int *b,int *a,int i,int j,int *m)
{
	if(j>=1)
	{
		dealarray(b,a,i-1,j-1,m);
	}
	else//����i=1,j=0�ĳ�ʼ��� 
	{
		if(a[i]!=a[j])
		{
			b[(*m)++]=a[j];
			b[(*m)++]=a[i];
		}
		else
		{
			b[(*m)++]=a[j];
//			printf("%d\n",a[j]);   	//�����ã���ӡ�ظ��� 
		} 
		
		return ;
	}
	if(a[i]!=a[j])
	{
		b[(*m)++]=a[i];
	}
	else
	{
		;
//		printf("%d\n",a[j]);	//�����ã���ӡ�ظ�
	} 
}
void random(int n)
{
	int a[n],b[n],i,m=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	printf("\n");
	InsertionSort(a,n);
	dealarray(b,a,n-1,n-2,&m);
	printf("%d\n",m);
	for(i=0;i<m;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
}
int main()
{
	int i,sum;
	scanf("%d",&sum);
	random(sum);
} 
