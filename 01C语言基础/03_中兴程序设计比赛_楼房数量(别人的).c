#include<stdio.h>
int CountHourse(int row, int col, int (*matrix)[10])
{
		int i,j;
        // ��һ�α����������Ͻǿ�ʼ
        int leftRoof[10][10];// ��־��λ�õ�����Ƿ����ݶ�
        int topRoof[10][10]; // ��־��λ�õ��Ϸ��Ƿ����ݶ�
        int count1 = 0;
        // �ٽ���һ�α����������½ǿ�ʼ����
        int rightRoof[10][10];    // ��־��λ�õ��ұ��Ƿ����ݶ�
        int bottomRoof[10][10]; // ��־��λ�õ��·��Ƿ����ݶ�
        int count2 = 0;
		memset(leftRoof,0,sizeof(leftRoof));
		memset(topRoof,0,sizeof(topRoof));
		memset(rightRoof,0,sizeof(rightRoof));
		memset(bottomRoof,0,sizeof(bottomRoof));   
        for(i = 0; i < 10; i++)        
        {
            for(j = 0; j < 10; j++)
            {
                if(matrix[i][j] == 1)
                {
                    if(j < col - 1)
                        leftRoof[i][j + 1] = 1;
                    if(i < row - 1)
                        topRoof[i + 1][j] = 1;
                    if( (!leftRoof[i][j]) && (!topRoof[i][j]) )
                        count1++;
                }
            }
        }
        for(i = 10 - 1; i >= 0; i--)
        {
            for(j = 10 - 1; j >= 0; j--)
            {
                if(matrix[i][j] == 1)
                {
                    if(j > 0)
                        rightRoof[i][j - 1] = 1;
                    if(i > 0)
                        bottomRoof[i - 1][j] = 1;
                    if( (!rightRoof[i][j]) && (!bottomRoof[i][j]) )
                        count2++;
                }
            }
        }
        return count1 < count2? count1 : count2;    // �������α���ͳ���еĽ�С��	
}

int main()
{
	int n=10,m=10;
	int grid[10][10]={
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,0,0,0},
						{0,0,0,0,0,1,1,0,0,0},
						{0,0,0,1,1,1,1,1,1,1},
						{0,0,0,0,0,0,0,1,0,1},
						{0,0,0,0,0,0,0,1,1,1},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}};
	printf("%d\n",CountHourse(n,m,grid));
	return 0; 
}

