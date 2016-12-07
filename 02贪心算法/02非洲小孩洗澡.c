#include<stdio.h>

struct Node
{
	int start;
	int end;
}a[100];

void sort(struct Node* A,int N)
{
	int j,p;
	struct Node temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1].end>temp.end;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 

int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{	
		int a1,a2,b1,b2,temp,sum=1;
		for(i=0;i<n;i++)
		{
			scanf("%d:%d-%d:%d",&a1,&a2,&b1,&b2);
			a2+=a1*60;b2+=b1*60;
			if(a2 > b2)
			{
				temp=a2;
				a2=b2;
				b2=temp;
			}
			a[i].start=a2;
			a[i].end=b2;
		}
		sort(a,n);
		for(i=0,j=0;i<n;i++)
		{
			if(a[i].start > a[j].end)
			{
				j=i;
				sum++;
			}
		}
		printf("%d\n",sum);
	}
}  
 
