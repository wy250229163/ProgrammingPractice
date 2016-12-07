#include<stdio.h> 

int main()
{
	int n,i,t;
	char words[3];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",words);
		if(words[0]>words[1])
		{
			t=words[0];
			words[0]=words[1];
			words[1]=t;
		}
		if(words[0]>words[2])
		{
			t=words[0];
			words[0]=words[2];
			words[2]=t;
		}
		if(words[1]>words[2])
		{
			t=words[1];
			words[1]=words[2];
			words[2]=t;
		}
		printf("%c %c %c\n",words[0],words[1],words[2]);	
	}
	return 0;	
} 
