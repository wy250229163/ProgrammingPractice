#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
	char a[1001],b[1001];
	int flag;
	while(1)
	{
		scanf("%s%s",a,b);
		if(a[0]=='0' && b[0]=='0') break;
		int lena=strlen(a);
		int lenb=strlen(b);
		int pos;
		if(strcmp(a,b)==0)
		{
			flag=2;		
		}
		else
		{
			if(a[0]!='-' && b[0]!='-')
			{
				if(lena>lenb)
					flag=0;	
				else if(lena<lenb)
					flag=1;
				else
				{
					pos=0;
					while(a[pos]==b[pos]) pos++;
					if(a[pos]>b[pos])
						flag=0;
					else
						flag=1;
				} 
			}
			else if(a[0]=='-' && b[0]=='-')
			{
				if(lena>lenb)
					flag=1;	
				else if(lena<lenb)
					flag=0;
				else
				{
					pos=1;
					while(a[pos]==b[pos]) pos++;
					if(a[pos]>b[pos])
						flag=1;
					else
						flag=0;
				}
			}
			else
			{
				if(b[0]=='-')
					flag=0;
				else if(a[0]=='-')
					flag=1;
			}			
		}
		switch(flag)
		{
			case 0:
				printf("a>b\n");
				break;
			case 1:
				printf("a<b\n");
				break;
			case 2:
				printf("a==b\n");
				break;	
		} 
	}
} 




//�ȴ�С
//ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�2
//����
//���������ܴ���������ܲ����жϳ������������Ĵ�С�أ�
//
//����123456789123456789Ҫ����-123456
//
//����
//ÿ���������ռһ�У���������������1000λ��10��������a,b
//���ݱ�֤�����a,bû��ǰ׺��0��
//�������0 0��ʾ���������������������������10��
//���
//���a>b�������a>b�������a<b�������a<b��,�������������a==b����
//��������
//111111111111111111111111111 88888888888888888888
//-1111111111111111111111111  22222222
//0 0
//�������
//a>b
//a<b
//�ϴ���
//���ƴ�