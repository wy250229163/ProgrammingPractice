#include<stdio.h>
#include<string.h>
char getFinalword(char (*words)[10],int num)
{
	return words[num][strlen(words[num])-1];
}
char getStartword(char (*words)[10],int num)
{
	return words[num][0];
}
int isAllone(int *mark,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(mark[i]==0)
			return 0;
	}
	if(i==n)
		return 1;
}
int tryConnected(char (*words)[10],int num,int *mark,int n)
{
	int i=0;
	char finalword,startword;
	mark[num]=1;
//	printf("%s\n",words[num]);    //µ÷ÊÔÓÃ 
	finalword=getFinalword(words,num);
	for(i=0;i<n;i++)
	{
		if(mark[i]==0)
		{
			startword=getStartword(words,i);
			if(finalword == startword)
			{
				tryConnected(words,i,mark,n);
			}
		}
	}
	if(isAllone(mark,n))
		return 1;
	else
		return 0; 
}
int isConnected(char (*word)[10],int n)
{
	int i,j,mark[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
			mark[j]=0;
		if(tryConnected(word,i,mark,n))
			break;
	}
	if(i<n)
		return 1;
	else
		return 0;
}
int main()
{
	int n,i;
	char words[200][10];
	while(1)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",words[i]);
		}	
		if(isConnected(words,n))
			printf("YES\n");
		else
			printf("NO\n");		
	} 

}
