#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_VERTEX_NUM 1001
int Parent[MAX_VERTEX_NUM];//���鼯
int Degree[MAX_VERTEX_NUM];//��¼����Ķ�

int Find_parent(int x) //���鼯���Ҹ� 
{
	if(x==Parent[x])
		return x;
	return Find_parent(Parent[x]);
}
void init(int p) //�������Ϊ������� 
{
	for(int i=1;i<=p;i++)
	{
		Parent[i]=i;
		Degree[i]=0;
	}
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int P,Q;
		cin>>P>>Q;
	 	init(P);
	 	while(Q--)
	 	{
	 		int A,B;
	 		cin>>A>>B;
	 		Degree[A]++;Degree[B]++;
	 		int flag_A=Find_parent(A);
	 		int flag_B=Find_parent(B);
	 		if(flag_A!=flag_B) //����ͬһ�����Ͼͺϲ� 
	 			Parent[A]=flag_B;
	 	}
	 	int num_root=0; //��¼���鼯���� 
		int num_odd_degree=0; //��¼���������Ķ������ 
		for(int i=1;i<=P;i++)
		{
			if(Parent[i]==i)
				num_root++;
			if(Degree[i]%2==1)
				num_odd_degree++;
		}
		
		//����ͼ��ŷ��·������,���ȱ�֤ͼ��ͨ
		//��������ȶ���ĸ���Ҫôû��(ŷ����)��Ҫô����(ŷ��·��) 
		if(num_root==1 && (num_odd_degree==0||num_odd_degree==2))  
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
} 

/****
һ�ʻ�����
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
zyc��С�ͱȽ�ϲ����һЩС��Ϸ�����оͰ�����һ�ʻ��������������дһ�������ж�һ��ͼ�Ƿ��ܹ���һ�ʻ�������

�涨�����еı߶�ֻ�ܻ�һ�Σ������ظ�����

����
��һ��ֻ��һ��������N(N<=10)��ʾ�������ݵ�������
ÿ��������ݵĵ�һ��������������P,Q(P<=1000,Q<=2000)���ֱ��ʾ��������ж��ٸ�����Ͷ��������ߡ�����ı�Ŵ�1��P��
����Q�У�ÿ��������������A,B(0<A,B<P)����ʾ���ΪA��B������֮�������ߡ�
���
������ڷ������������ߣ������"Yes",
��������ڷ������������ߣ����"No"��
��������
2
4 3
1 2
1 3
1 4
4 5
1 2
2 3
1 3
1 4
3 4
�������
No
Yes
****/