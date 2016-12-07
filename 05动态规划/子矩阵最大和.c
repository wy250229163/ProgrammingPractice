#include<stdio.h>
#include<string.h>

int num[101][101];

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		int i,j,k;
		memset(num,0,sizeof(num));
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{
				scanf("%d",&num[i][j]);	
				num[i][j]+=num[i-1][j];			
			}
		int temp=0;
		int max=num[1][1];
		int tempmax;
		for(i=1;i<=r;i++)
		{
			for(j=i;j<=r;j++)
			{
				tempmax=0;	
				for(k=1;k<=c;k++)
				{
					temp=num[j][k]-num[i-1][k];
					tempmax=(tempmax>=0?tempmax:0)+temp;
					max=tempmax>max?tempmax:max;
				}		
			}
		}
		printf("%d\n",max);
	}
	return 0;
} 
 
 
// ����
//ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�5
//����
//����һ����������ɶ�ά����r*c����������Ҫ�ҳ�����һ���Ӿ���ʹ������Ӿ����ڵ�����Ԫ��֮����󣬲�������Ӿ����Ϊ����Ӿ��� 
//���ӣ�
//0 -2 -7 0 
//9 2 -6 2 
//-4 1 -4 1 
//-1 8 0 -2 
//������Ӿ���Ϊ��
//
//9 2 
//-4 1 
//-1 8 
//��Ԫ���ܺ�Ϊ15�� 
//
//����
//��һ������һ������n��0<n<=100��,��ʾ��n��������ݣ�
//ÿ��������ݣ�
//��һ��������������r��c��0<r,c<=100����r��c�ֱ���������к��У�
//�����r�У�ÿ����c��������
//���
//������������Ӿ����Ԫ��֮�͡�
//��������
//1
//4 4
//0 -2 -7 0 
//9 2 -6 2 
//-4 1 -4 1 
//-1 8 0 -2 
//�������
//15