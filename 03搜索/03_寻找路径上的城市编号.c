#include<stdio.h>
#include<stdlib.h>
struct cityNode
{
	int toCity; 
	struct cityNode* nextCity;
};

void DFS(struct cityNode* city , int* lastcityarry ,int s)
{
	struct cityNode* p;
	p=&city[s];
	while(p->nextCity!=NULL)
	{
		p=p->nextCity;
		lastcityarry[p->toCity]=s;
		DFS(city, lastcityarry, p->toCity);
	}
} 

int main()
{
	int M;
	scanf("%d",&M);
	while(M--)
	{
		int N,S;
		int i,j,a,b;
		scanf("%d%d",&N,&S);
		int lastCityNum[N+1];
		struct cityNode cityNum[N+1];
		memset(lastCityNum,0,sizeof(lastCityNum));
		for(i=0;i<=N;i++)
		{
			cityNum[i].toCity=0;
			cityNum[i].nextCity=NULL;
		}
		
		struct cityNode* temp;		
		for(i=1;i<N;i++)
		{
			struct cityNode* p;
			p=(struct cityNode *)malloc(sizeof(struct cityNode));
			scanf("%d%d",&a,&b);
			p->toCity=b;
			p->nextCity=NULL;
			temp=&cityNum[a];
			while(temp->nextCity!=NULL)
				temp=temp->nextCity;
			temp->nextCity=p;
		}
		
		struct cityNode terminal;
		terminal.toCity=0;
		terminal.nextCity=NULL;
		for(i=1;i<=N;i++)
		{
			temp=&cityNum[i];
			while(temp->nextCity!=NULL)
				temp=temp->nextCity;
			temp->nextCity=&terminal;
		}

		DFS(cityNum,lastCityNum,S);
		lastCityNum[S]=-1;
		for(i=1;i<=N;i++)
			printf("%d ",lastCityNum[i]);
		printf("\n");
	}
}
 
 
 
// ���ĵĹ���
//ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�3
//����
//��һ�����ĵĹ�������N�����У���N�����м�ֻ��N-1��·�����N�������������������ڣ�Tom�ڵ�S�ų��У������Ÿù���ͼ������֪������Լ�Ҫȥ�ι۵�T�ų��У����뾭����ǰһ�������Ǽ��ų��У������㲻���ظ���·����
//����
//��һ������һ������M��ʾ�������ݹ���M(1<=M<=5)��
//ÿ��������ݵĵ�һ������һ��������N(1<=N<=100000)��һ��������S(1<=S<=100000)��N��ʾ���е��ܸ�����S��ʾ�ι������ڳ��еı��
//����N-1�У�ÿ��������������a,b(1<=a,b<=N)����ʾ��a�ų��к͵�b�ų���֮����һ��·��ͨ��
//���
//ÿ�����������N�������������У���i������ʾ��S�ߵ�i�ų��У�����Ҫ��������һ�����еı�š�������i=Sʱ�������-1��
//��������
//1
//10 1
//1 9
//1 8
//8 10
//10 3
//8 6
//1 2
//10 4
//9 5
//3 7
//�������
//-1 1 10 10 9 8 3 1 1 8