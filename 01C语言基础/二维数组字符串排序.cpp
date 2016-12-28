#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

char words[10][30];
char *Addrwords[10];

int cmp(char *a,char *b)
{
	if(a[0]==b[0])
	{
		if(a[strlen(a)-1]==b[strlen(b)-1])
			return 0;
		else
			return a[strlen(a)-1]<b[strlen(b)-1];
	}
	else
		return a[0]<b[0];
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>words[i];
	}
	for(int i=0;i<N;i++)
	{
		Addrwords[i]=words[i];
	}
	sort(&Addrwords[0],&Addrwords[0]+N,cmp);
	cout<<"The result is:"<<endl;
	for(int i=0;i<N;i++)
		cout<<Addrwords[i]<<endl;
}

/**
5
asc
gxw
abb
red
ade
**/