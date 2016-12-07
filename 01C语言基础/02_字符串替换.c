#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,length;
	char words[1000];
	while(gets(words))
	{	
		for(i=0;i<strlen(words);++i)
		{
			if(words[i]='y' && words[i+1]=='o' && words[i+2]=='u')
			{
				words[i]='w';
				words[i+1]='e';
				for(j=i+2;j<strlen(words);++j)
					words[j]=words[j+1];
				printf("%s\n",words);
			}
		}
		printf("%s\n",words);
	}
	return 0;
} 
