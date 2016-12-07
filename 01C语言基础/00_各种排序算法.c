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

/****************************************堆排序****************************************/
typedef struct heap_t
{
	int *arr;
	int heapMaxIndex; //最大索引，a[10],则值为9 
	int arrLength; //长度，10 
}Heap;

void maxHeapify(Heap *hq,int nodei)
{
/**********************************************************************
思想是：从一个节点i，和他的孩子leftchild(i)，rightChild(i)中找到最大的，
然后其索引存放在largest中。如果i是最大的。那么i为根的子树已经是最大堆，
程序结束。
否则i的某个子节点有最大元素，那么i的值和largest的值交换。下标为largest的
节点在交换后作为父节点，那么他可能又违反堆性质，因此递归调用该函数。
**********************************************************************/	
	int l=(nodei+1)<<1-1; //左儿子的索引值
	int r=(nodei+1)<<1;   //右儿子的索引值
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
对于1个个数为n的堆，从上面堆的图中可以分析得到，
n/2-1之前的都是父节点。之后的都是叶子节点，
我们只需要对父节点进行maxHeapify就可以了。 
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

/**************************插入排序************************/
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

/**************************希尔排序************************/
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

/**************************归并排序************************/
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

/*************************快速排序**************************/
ElementType Median3(ElementType A[],int left,int right)
{
/*
选定枢纽元函数，先将左中右三个数按大小排序，选定中间为枢纽元。
选定后将中心的枢纽元交换到右边倒数第二个位置上去 
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
	
	if(left+3 <= right)    //一定范围之外用快排，小范围用插排 
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
