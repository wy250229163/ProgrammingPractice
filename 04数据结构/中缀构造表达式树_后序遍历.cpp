#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

struct tree
{
	char c;
	struct tree* left;
	struct tree* right;
};

stack<struct tree*>subTreeStack;
stack<char>operatorStack;

int isOperator(char c)
{
	return (c=='*'||c=='/'||c=='+'||c=='-');
}

struct tree* BuildTree(char* str)
{
	struct tree* node;
	int pos;
	for(pos=0;pos<strlen(str);pos++)
	{
		if(str[pos]>='0' && str[pos]<='9') //操作数则构造叶子节点 
		{
			node=(struct tree*)malloc(sizeof(struct tree));
			node->c=str[pos];
			node->left=NULL;
			node->right=NULL;		
			subTreeStack.push(node); //叶子节点压栈 
		}
		else if(isOperator(str[pos])) 
		{
			if(!operatorStack.empty() && (str[pos]=='+' || str[pos]=='-'))
			{
				node=(struct tree*)malloc(sizeof(struct tree));
				node->c=operatorStack.top();
				node->right=subTreeStack.top();
				subTreeStack.pop();
				node->left=subTreeStack.top();
				subTreeStack.pop();
				
				subTreeStack.push(node);
				
				operatorStack.pop();
				operatorStack.push(str[pos]);
			}
			else
				operatorStack.push(str[pos]);
		}
	}
	while(!operatorStack.empty())
	{
		node=(struct tree*)malloc(sizeof(struct tree));
		node->c=operatorStack.top();
		operatorStack.pop();
		node->right=subTreeStack.top();
		subTreeStack.pop();
		node->left=subTreeStack.top();
		subTreeStack.pop();
		
		subTreeStack.push(node);
	}
	return subTreeStack.top();
}

void printTree(struct tree* node)  //后序遍历 
{
	if(node==NULL)
		return ;
	printTree(node->right);
	printTree(node->left);
	printf("%c",node->c);
} 

int main(void)
{
	char str[] = "3*4+5-2/1";
	struct tree* root=BuildTree(str);
	printTree(root);
} 