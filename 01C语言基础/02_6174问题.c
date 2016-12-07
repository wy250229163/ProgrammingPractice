#include<stdio.h>
void sort(int A[],int N,int Flag)
{
	int j,p;
	int temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		if(Flag)
		{
			for(j=p;j>0&&A[j-1]>temp;j--)
				A[j]=A[j-1];			
		}
		else
		{
			for(j=p;j>0&&A[j-1]<temp;j--)
				A[j]=A[j-1];			
		}
		A[j]=temp;
	}		
}
int realvalue(int *A)
{
	return (A[0]*1000+A[1]*100+A[2]*10+A[3]);
}
int descretevalue(int *A,int num)
{
	A[0]=num/1000;
	A[1]=num%1000/100;
	A[2]=num%100/10;
	A[3]=num%10;
}
void loopsort(int *A,int *time)
{
	int temp1[4];
	int temp2[4];
	int temp[4];
	int i,tempp;
	for(i=0;i<4;i++)
	{
		temp1[i]=A[i];
		temp2[i]=A[i];
	}
	sort(temp1,4,1); //1ÎªÉýÐò 
	sort(temp2,4,0); //0Îª½µÐò 
	tempp=realvalue(temp2)-realvalue(temp1);
	descretevalue(temp,tempp);
	if(tempp==realvalue(A))
	{
		(*time)++;
//		printf("%d\n",tempp);
		return ;		
	}
	else
	{
		(*time)++;		
		loopsort(temp,time);
//		printf("%d\n",tempp);
	}
}

int main()
{
	int n,m,timee;
	int num[4];
	scanf("%d",&n);
	while(n--)
	{
		timee=0;
		scanf("%d",&m);
		descretevalue(num,m);
		loopsort(num,&timee);
		printf("%d\n",timee);
	}
	return 0;
}
