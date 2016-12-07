/******
�����������û���ǵ��� max(add(1,2),7)
*******/
#include<cstdio>
#include<cstring>
#include<stack> 

using namespace std;
stack<char> oper;
stack<int> num;

void deal_Num(char *s,int start,int end)
{
	int i;
	int a,temp=0,k=1;
	for(i=end;i>=start;i--)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			temp+=(s[i]-'0')*k;
			k*=10;
		}
		if(s[i]==',')
		{
			a=temp;
			temp=0;
			k=1;
		} 
	}
	num.push(temp);
	num.push(a); 
}

int Caculate(char s,int a,int b)
{
	switch(s)
	{
		case 'n':
			return a<b?a:b;
		case 'x':
			return a>b?a:b;
		case 'd':
			return a+b;
	}
}

int main(void)
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char str[300];
		scanf("%s",&str);
		int len=strlen(str);
		int i,j,k;
		int a,b,c;
		i=j=k=0;
		if(str[0]>'0' && str[0]<'9')
			printf("%s\n",str);
		else
		{
			for(i=0;i<len;i++)
			{
				if(str[i]=='(')
					oper.push(str[i-1]); 
				if(str[i-1]=='(' && str[i]>='0' && str[i]<='9')
					j=i;
				if(str[i]==')' && str[i-1]>='0' && str[i-1]<='9')
					deal_Num(str,j,i-1);
				if(str[i]==')')
				{
					a=num.top();num.pop();
					b=num.top();num.pop(); 
					num.push(Caculate(oper.top(),a,b));
					oper.pop();
				}
			}
			printf("%d\n",num.top());
			num.pop();
		}
	} 
}


//���ʽ��ֵ
//ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�3
//����
//Dr.Kong��ƵĻ����˿��������˼Ӽ��������Ժ������ѧ����һЩ�򵥵ĺ�����ֵ�����磬��֪������min(20,23)��ֵ��20 ��add(10,98) ��ֵ��108�ȵȡ�����ѵ����Dr.Kong��ƵĻ����˿������������һ��Ƕ�׵ĸ����ӵı��ʽ��
//������ʽ���Լ򵥶���Ϊ:
//1. һ������ʮ������ x ��һ�����ʽ��
//2. ��� x �� y �� ���ʽ���� ����min(x,y )Ҳ�Ǳ��ʽ,��ֵΪx,y �е���С����
//3. ��� x �� y �� ���ʽ���� ����max(x,y )Ҳ�Ǳ��ʽ,��ֵΪx,y �е��������
//4����� x �� y �� ���ʽ���� ����add(x,y )Ҳ�Ǳ��ʽ,��ֵΪx,y ֮�͡�
//���磬 ���ʽ max(add(1,2),7) ��ֵΪ 7��
//�����д���򣬶��ڸ�����һ����ʽ������ Dr.Kong �����ȷ�𰸣��Ա�У�Կ�����������
//����
//��һ�У� N ��ʾҪ����ı��ʽ���� ��1�� N �� 10�� 
//��������N�У� ÿ����һ���ַ�������ʾ����ֵ�ı��ʽ
//�����ʽ�в����ж���Ŀո�ÿ�в�����300���ַ������ʽ�г��ֵ�ʮ����������
//����1000����
//���
//�����N�У�ÿһ�ж�Ӧһ�����ʽ��ֵ��
//��������
//3
//add(1,2) 
//max(1,999) 
//add(min(1,1000),add(100,99)) 
//�������
//3
//999
//200