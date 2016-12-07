#include<stdio.h>
#include<string.h>

int height[1000];
int width[1000];

void sortWithArea(int *h,int *w,int len)
{
	int i,j;
	int temp,temph,tempw;
	int area[len];
	for(i=0;i<len;i++)
		area[i]=h[i]*w[i];
	for(i=1;i<len;i++)
	{
		temp=area[i];
		temph=h[i];tempw=w[i];
		for(j=i; j>0 && area[j-1]<temp ;j--)
		{
			area[j]=area[j-1];
			h[j]=h[j-1];
			w[j]=w[j-1];
		}
		area[j]=temp;
		h[j]=temph;
		w[j]=tempw;
	}
}

int main(void)
{
	int N,n;
	int i,j;
	scanf("%d",&N); //�������� 
	while(N--)
	{
		scanf("%d",&n); //���θ��� 
		int sum[n];
		int max,maxlen=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&height[i],&width[i]);
		sortWithArea(height,width,n);
		for(i=0;i<n;i++)
		{
			max=0;
			sum[i]=1;
			for(j=i-1;j>=0;j--)
			{
				if((((height[j]>height[i])&&(width[j]>width[i])) || ((height[j]>width[i])&&(width[j]>height[i]))) && sum[j]>max)
					max=sum[j];
			}
			sum[i]+=max;
			if(sum[i]>maxlen)
				maxlen=sum[i];
		}
		printf("%d\n",maxlen);
	}
}
 
 
//����Ƕ�� 
//ʱ�����ƣ�3000 ms | �ڴ����ƣ�65535 KB 
//�Ѷȣ�4 
//���� 
//��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ������磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ� 
//���� 
//��һ����һ��������N(0<N<10)����ʾ�������������� 
//ÿ��������ݵĵ�һ����һ��������n����ʾ������������к��о��εĸ���(n<=1000) 
//����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ� 
//��� 
//ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ�� 
//�������� 
//1 
//10 
//1 2 
//2 4 
//5 8 
//6 10 
//7 9 
//3 1 
//5 8 
//12 10 
//9 7 
//2 2 
//������� 
//5