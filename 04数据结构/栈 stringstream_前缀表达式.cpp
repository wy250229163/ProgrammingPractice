#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;
stack<double> Oper;

double Operate(char ope)
{
	double a,b;
	a=Oper.top();Oper.pop();
	b=Oper.top();Oper.pop();
	if(ope=='+')
		return a+b;
	else if(ope=='-')
		return a-b;
	else if(ope=='*')
		return a*b;
	else if(ope=='/')
		return a/b;
}

int main(void)
{
	char str[2000];
	int slength;
	while(gets(str))
	{
		slength=strlen(str);
		double tempnum=0;
		int i,j,k=0,dot=0;
		i=j=(slength-1);
		while(i>=0)
		{
			if(str[i]==' ')
			{
				tempnum=0;
				if((j-i)>1)
				{
					for(k=i+1;k<=j;k++)
					{
						if(str[k]!='.')
							tempnum=tempnum*10+str[k]-'0';
						else
							dot=k;
					}
					tempnum=tempnum/(10*(j-dot));
				//	printf("push2: %f \n",tempnum);
					Oper.push(tempnum);
				}
				else
				{
					if(str[i+1]>='0' && str[i+1]<='9')
					{
				//		printf("push1: %d \n",str[i+1]-'0');
						Oper.push((double)(str[i+1]-'0'));						
					}
					else
						Oper.push(Operate(str[i+1]));
				}
				j=i-1;
			}
			if(i==0)
				printf("%.2lf\n",Operate(str[i]));
			i--;
		}
	}
}

/************** stringstream ******************
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

stringstream s;
string str;

double ac()
{
    string str;
    s>>str; //从流中取出字符串
    if(str[0] == '+')
        return ac() + ac();
    if(str[0] == '-')
        return ac() - ac();
    if(str[0] == '*')
        return ac() * ac();
    if(str[0] == '/')
        return ac() / ac();
    return atof(str.c_str()); //返回double类型数据，遇非数字字符停止
}

int main()
{
    while(getline(cin, str))
    {
        s.clear();
        s<<str;
        printf("%.2lf\n", ac());
    }
    return 0;
}
*******************************************/