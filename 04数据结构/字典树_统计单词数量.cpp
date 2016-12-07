#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int maxn=0;
struct trie
{
	char c;
	int cnt;
	bool exist;
	trie *child[26];
};
char str[20];
char aimstr[20];

void insert(trie* root,char* str)
{
	char* p=str;
	while(*p)
	{
		int key=*p-'a';
		if(root->child[key]==0)
		{
			trie *np=new trie;
			np->c=*p;
			np->cnt=0;
			np->exist=0;
			root->child[key]=np;			
		}
		root=root->child[key];
		p++;
	}
	root->exist=true;
	root->cnt++;
	if(maxn<root->cnt)
	{
		maxn=root->cnt;
		strcpy(aimstr,str);
	}
}

int main(void)
{
	trie* root=new trie;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		insert(root,str);
	}
	printf("%s %d\n",aimstr,maxn);
	return 0;
}
 