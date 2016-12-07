#include<stdio.h>
#include<math.h>
struct Node
{
	double left;
	double right;
}N[10000];

void sort(struct Node* A,int N)  //��˵���С�������� 
{
	int j,p;
	struct Node temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1].left>temp.left;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 

int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int i,j,n,w,h,x,r;
		int num=-1;
		int total=0;
		int maxp=0,tempmax=0;
		scanf("%d%d%d",&n,&w,&h);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&r);
			if(2*r<h)
				continue;
			else
				num++;
			N[num].left=(double)x-sqrt(r*r-h*h/4);
			N[num].right=(double)x+sqrt(r*r-h*h/4);
		}
		sort(N,num+1); //��������˵���С�������� 
		for(i=0;i<num+1;i++)
		{
			if(N[i].left<=maxp)  //����������64�У��Ϳ����ж��������Ƿ��м���� 
			{
				tempmax=N[i].right;
				while(N[i].left<=maxp)
				{
					if(N[i].right>tempmax)
						tempmax=N[i].right;
					i++;
					if(i==num+1)
						break;	
				}
				maxp=tempmax;
				total++;
				i--;
			}
			if(maxp>=w)
				break;				
		}
		if(maxp>=w)	
			printf("%d\n",total);
		else
			printf("%d\n",0);
	}
	return 0;
}
 
 
 
// ����
//��һ���ƺ������w,����Ϊh,�����ęM���������ϲ�ͬλ�ô�װ��n(n<=10000)����״����ˮװ�ã�ÿ����ˮװ��i��ˮ��Ч����������Ϊ���İ뾶ΪRi��Բ������ʪ�����ڸ�������ˮװ����ѡ�����ٵ���ˮװ�ã���������ƺȫ����ʪ��
//����
//��һ������һ��������N��ʾ����n�β������ݡ�
//ÿһ��������ݵĵ�һ������������n,w,h��n��ʾ����n����ˮװ�ã�w��ʾ��ƺ�ĺ��򳤶ȣ�h��ʾ��ƺ�����򳤶ȡ�
//����n�У�������������xi��ri,xi��ʾ��i����ˮװ�õĵĺ����꣨�����Ϊ0����ri��ʾ����ˮװ���ܸ��ǵ�Բ�İ뾶��
//���
//ÿ������������һ������������ʾ����Ҫ���ٸ���ˮװ�ã�ÿ���������ռһ�С�
//���������һ���ܹ���������ƺʪ��ķ����������0��
//��������
//2
//2 8 6
//1 1
//4 5
//2 10 6
//4 5
//6 5
//�������
//1
//2