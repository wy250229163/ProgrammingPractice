#include<stdio.h>
struct Node
{
	int left;
	int right;
}a[100];

void sort(struct Node* A,int N)
{
	int j,p;
	struct Node temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1].right>temp.right;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 
int main()
{
	int n,i,j,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].left,&a[i].right);
		sort(a,n);
		for(i=0,j=0;i<n;i++)
		{
			if(a[i].left > a[j].right)
			{
				j=i;
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return ;
}

//�ҵ�
//ʱ�����ƣ�2000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�2
//����
//����ѧ��ʱ����ʦ����LYHһЩ�����䣬����ȡ�����ٵĵ㣬ʹ��ÿ����������������һ���㡣�����⼸��LYH̫æ�ˣ����ǰ������
//����
//����������ݡ�
//ÿ������������һ��N����ʾ��N�������䣨N��100)��
//������N�У�ÿ������������a��b(0��a��b��100������ʾ����������˵㡣
//���
//���һ����������ʾ������Ҫ�Ҽ����㡣
//��������
//4
//1 5
//2 4
//1 4
//2 3
//3
//1 2
//3 4
//5 6
//1
//2 2
//�������
//1
//3
//1