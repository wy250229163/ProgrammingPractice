#include<stdio.h>
#include<stdlib.h>

#define ElementType int

void Swap(int *a,int *b) 
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/****************************************������****************************************/
typedef struct heap_t
{
	int *arr;
	int heapMaxIndex; //���������a[10],��ֵΪ9 
	int arrLength; //���ȣ�10 
}Heap;

void maxHeapify(Heap *hq,int nodei)
{
/**********************************************************************
˼���ǣ���һ���ڵ�i�������ĺ���leftchild(i)��rightChild(i)���ҵ����ģ�
Ȼ�������������largest�С����i�����ġ���ôiΪ���������Ѿ������ѣ�
���������
����i��ĳ���ӽڵ������Ԫ�أ���ôi��ֵ��largest��ֵ�������±�Ϊlargest��
�ڵ��ڽ�������Ϊ���ڵ㣬��ô��������Υ�������ʣ���˵ݹ���øú�����
**********************************************************************/	
	int l=(nodei+1)<<1-1; //����ӵ�����ֵ
	int r=(nodei+1)<<1;   //�Ҷ��ӵ�����ֵ
	int largest=0;
	int heapMaxI=hq->heapMaxIndex;
	 
	if( l<=heapMaxI && hq->arr[l]>hq->arr[nodei]) 
		largest=l; 
	else
		largest=nodei;
	if( r<=heapMaxI && hq->arr[r]>hq->arr[largest])
		largest=r;
		
	if(largest!=nodei)
	{
		int temp;
		temp = hq->arr[nodei];
		hq->arr[nodei] = hq->arr[largest];
		hq->arr[largest]=temp;
		
		maxHeapify(hq,largest);
	}
	else
		return ;
} 

Heap *CreatHeap(int *arrp,int arrLength,Heap *heap)
{
/**********************************************
����1������Ϊn�Ķѣ�������ѵ�ͼ�п��Է����õ���
n/2-1֮ǰ�Ķ��Ǹ��ڵ㡣֮��Ķ���Ҷ�ӽڵ㣬
����ֻ��Ҫ�Ը��ڵ����maxHeapify�Ϳ����ˡ� 
**********************************************/
	int i;
	heap->arr=arrp;
	heap->heapMaxIndex=arrLength-1;
	heap->arrLength=arrLength;
	
	for(i=arrLength>>1-1;i>=0;i--)
	{
		maxHeapify(heap,i);
	}
	return heap;
}

void HeapSort(ElementType A[],int N)
{
	int temp;
	int last;
	Heap hq,*phq;
	phq=CreatHeap(A,N,&hq);
	
	while(phq->heapMaxIndex > 0)
	{
		last=phq->heapMaxIndex;
		
		temp=phq->arr[last];
		phq->arr[last]=phq->arr[0];
		phq->arr[0]=temp;
		
		phq->heapMaxIndex--;
		maxHeapify(phq,0);
	}
} 

/***************************************************************************************/

/**************************��������************************/
void InsertionSort(ElementType A[],int N)
{
	int j,p;
	ElementType temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1]>temp;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 
/***********************************************************/

/**************************ϣ������************************/
void ShellSort(ElementType A[],int N) 
{
	int i,j,Increment;
	ElementType temp;
	for(Increment=N/2;Increment>0;Increment/=2)
	{
		for(i=Increment;i<N;i++)
		{
			temp=A[i];
			for(j=i;j>=Increment;j-=Increment)
			{
				if(temp<A[j-Increment])
					A[j]=A[j-Increment];
				else
					break;
			}
			A[j]=temp;
		}
	}
}
/***********************************************************/

/**************************�鲢����************************/
void Merge(ElementType A[],ElementType TempA[],int Lpos,int Rpos,int Rightend)
{
	int i,LeftEnd,NumElements,TempPos;
	LeftEnd=Rpos-1;
	TempPos=Lpos;
	NumElements=Rightend-Lpos+1;
	
	while(Lpos<=LeftEnd && Rpos<=Rightend)
	{
		if(A[Lpos] <= A[Rpos])
			TempA[TempPos++]=A[Lpos++];
		else
			TempA[TempPos++]=A[Rpos++];
	}
	while(Lpos<=LeftEnd)
		TempA[TempPos++]=A[Lpos++];
	while(Rpos<=Rightend)
		TempA[TempPos++]=A[Rpos++];
		
	for(i=0;i<NumElements;i++,Rightend--)
		A[Rightend]=TempA[Rightend];
}
void MSort(ElementType A[],ElementType TempA[],int left,int right)
{
	int center;
	if(left<right)
	{
		center=(left+right)/2;
		MSort(A,TempA,left,center);
		MSort(A,TempA,center+1,right);
		Merge(A,TempA,left,center+1,right);
	}
}
void MergeSort(ElementType A[],int N)
{
	ElementType *TempA;
	TempA=malloc(sizeof(ElementType)*N);
	if(TempA!=NULL)
	{
		MSort(A,TempA,0,N-1);
		free(TempA);
	} 
	else
	{
 		printf("No space for temp array!");
		exit(0);	
	}

} 

/**********************************************************/

/*************************��������**************************/
ElementType Median3(ElementType A[],int left,int right)
{
/*
ѡ����ŦԪ�������Ƚ�����������������С����ѡ���м�Ϊ��ŦԪ��
ѡ�������ĵ���ŦԪ�������ұߵ����ڶ���λ����ȥ 
*/
	int center=(left+right)/2;
	if(A[left]>A[center])
		Swap(&A[left],&A[center]);
	if(A[left]>A[right])
		Swap(&A[left],&A[right]);
	if(A[center]>A[right])
		Swap(&A[center],&A[right]);
	Swap(&A[center],&A[right-1]);
	return A[right-1]; 
}
void Qsort(ElementType A[],int left,int right)
{
	int i,j;
	ElementType Pivot;
	
	if(left+3 <= right)    //һ����Χ֮���ÿ��ţ�С��Χ�ò��� 
	{
		Pivot=Median3(A,left,right);
		i=left;
		j=right-1;
		for(;;)
		{
			while(A[++i]<Pivot);
			while(A[--j]>Pivot);
			if(i<j)
				Swap(&A[i],&A[j]);
			else
				break;
		}
		Swap(&A[i],&A[right-1]);
		Qsort(A,left,i-1);
		Qsort(A,i+1,right);
	}
	else
		InsertionSort(A+left,right-left+1);
	
}
void QuickSort(ElementType A[],int N)
{
	Qsort(A,0,N-1);
}
/**********************************************************/

int main(void)
{
	int i;
	int a[15]={32,12,-53,5,13,10,54,-23,44,22,64,-34,58,14,17};

//	HeapSort(a,15);
	InsertionSort(a,15);
//	ShellSort(a,15);
//	MergeSort(a,15);
//	QuickSort(a,15);
	for(i=0;i<15;i++)
		printf("%d ",a[i]);
	printf("\n");
}
