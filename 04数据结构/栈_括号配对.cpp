#include<stdio.h>
#include<string.h> 
#include<stack>
 
using namespace std;
 
int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char str[10002];
		stack<char>s;
		scanf("%s",str);
		int len=strlen(str);
		int i;
		for(i=0;i<len;i++)
		{
			if(s.empty())
				s.push(str[i]);
			else
			{
				if(str[i]==s.top()+1 || str[i]==s.top()+2)
					s.pop();
				else
					s.push(str[i]);
			}
		}
		if(s.empty())
			printf("Yes\n");
		else
			printf("No\n"); 
	} 
}