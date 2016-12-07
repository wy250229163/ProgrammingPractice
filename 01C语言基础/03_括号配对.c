#include<stdio.h>
#define EmptyTOS (-1)
//struct StackRecord;
//typedef struct StackRecord *Stack;
//struct StackRecord
//{
//	int Capacity;
//	int TopofStack;
//	char *Array;
//}
//
//Stack CreatStack(int MaxElements)
//{
//	Stack S;
//	S=malloc(sizeof(struct StackRecord));
//	S->Array=malloc(sizeof(char)*MaxElements);
//	S->Capacity=MaxElements;
//	S->TopofStack=EmptyTOS; ³õÊ¼»¯Õ» 
//	return S;
//}
//void Push(char X,Stack S)
//{
//	S->Array[++S->TopofStack]=X;
//}
//char Pop(Stack S)
//{
//	return S->Array[S->TopofStack--];
//}

int main()
{
	int i,total_num;
	char stk[100][10000];
	scanf("%d",&total_num);
	for(i=0;i<total_num;i++)
		gets(stk[i]);
	printf("%s\n",stk[0]);
} 
