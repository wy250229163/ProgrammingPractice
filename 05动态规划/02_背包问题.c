#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return a>b?a:b ;
}
int main()
{
	int W[25],sum=0,N=0,weight[100005];
	int i,j,temp;
	memset(weight,0,sizeof(weight));
 	while(scanf("%d",&N)!=EOF)
 	{
		for(i=0;i<N;i++)
		{ 
			scanf("%d",&W[i]);
			sum+=W[i]; 
		}
		temp=sum/2;
		for(i=0;i<N;i++)    	//��̬�滮�㷨 
		{
			for(j=temp;j>=W[i];j--)
			{
				weight[j]=max(weight[j-1],weight[j-W[i]]+W[i]);
			}
		}
		temp=(sum-weight[temp])-weight[temp];
		printf("%d\n",temp);
 	}
 	return 0;
} 
  
//����
//�������������³��壬acm��Աzb�����ա�zb���ں�CС�ӡ�never���人��ѵ�����������λ�ֵ����ʲô��ף���գ�
//�������飬zb����CС�Ӻ�never����ϲ�������ϣ�����һ�Ծ���һ�ѵ����֣�zb�����¶���������һ�����ϡ�
//����׼���������͸�CС�Ӻ�never��ʱ��������һ�����⣬never��CС�Ӳ���һ��ס��ֻ�ܰ����Ϸֳ����Ѹ����ǣ�
//Ϊ�˶�ÿ���˶���ƽ�����������ѵ�����֮����С��ÿ�����ϵ�������֪�����ܰ����ô��
//���� ����������ݣ�<=1500����������EOF��β ��һ��������������N (1 �� N �� 20) �ڶ�����N������W1, ��, Wn
//(1 �� Wi �� 10000)�ֱ����ÿ�����ϵ����� ��� ����ֳ����Ѻ�������� 
//��������
//5 
//5 8 13 27 14 
//�������
//3