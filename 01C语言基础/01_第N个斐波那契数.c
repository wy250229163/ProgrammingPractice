#include<stdio.h>
#include<stdlib.h>
void CreatFibArry(int *a,int start,int end)  
{
	a[0]=a[1]=1;
	if(start<2)  //��ʼ������2��ʼ�� 
		start=2;
 	if(end>=start)
 	{
 		CreatFibArry(a,start,end-1);
		a[end]=a[end-1]+a[end-2];
	}
	else
	{
		return ;
	}
} 
int main(void)
{
	int i,num;
	int intI[5];      //�洢����ֵ�ø��� 
	int Fibonacci[20];	//�洢쳲��������� 
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&intI[i]);
		if(i==0)   //�ڵ�һ������Ӧ�ó�ʼ������һ��쳲��������� 
		{
			CreatFibArry(Fibonacci,2,intI[i]);
			printf("%d\n",Fibonacci[intI[i]-1]);				
		}
		else	//�ӵڶ��ʼ��ÿ�ξ�Ҫ�Ƚ���ǰһ��Ĵ�С��ϵ�� 
		{
			if(intI[i]<=intI[i-1])   //�����ǰһ��С����ô����ֱ�ӿ��Զ�ȡ�������е��� 
			{
				printf("%d\n",Fibonacci[intI[i]-1]);
			}
			else    //���Ҫ��ȡ�ĵڶ���ȵ�һ�����ô�ȼ�������쳲��������У��ٶ�ȡ 
			{
				CreatFibArry(Fibonacci,intI[i-1],intI[i]);
				printf("%d\n",Fibonacci[intI[i]-1]);
			}	
		}	
	}
	return 0;
} 
