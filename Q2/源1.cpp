#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//动态规划法:
void LCSLength(int m, int n, int* x, int* y, int **c, int **b)
{
	int i, j;

	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (j = 1; j <= n; j++)
		c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
}
void LCS(int i, int j, int* x, int** b)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		LCS(i - 1, j - 1, x, b);
		printf("%d ", x[i - 1]);
	}
	else if (b[i][j] == 1)
		LCS(i - 1, j, x, b);
	else
		LCS(i, j - 1, x, b);
}


int main(void)
{

	//char *str1="dfahgduuengtlkjaohhgafghggdkkj";
	//char *str2="dfahgduuengtlkjaohhgafghggdkkj";
	//char* str1 = (char *)"ABCBDAB";
	//char* str2 = (char *)"BDCABA";
	int A1[] = { 3,45,56,7,4,8,9,10 }; 
	int A2[]= { 3,5,6,7, 8,4,9,10 };
	int i, j;
	int m = sizeof(A1) / sizeof(A1[0]);
	int n = sizeof(A2) / sizeof(A2[0]);
	int m1 = m + 1;
	int n1 = n + 1;
	int** c , ** b;
	c = new int* [m1];
	b = new int* [m1];
	for (i = 0; i < m1; i++)
	{
		c[i] = new int[n1];
		b[i] = new int[n1];
		for (j = 0; j < n1; j++) {
			c[i][j] = 0;
			b[i][j] = 0;
		}
	}
	for (int a = 0; a < m; a++) {
		printf("%d ", A1[a]);
	}
	printf("\n");
	
	for (int a = 0; a < m; a++) {
		printf("%d ", A2[a]);
	}

	LCSLength(m, n, A1, A2, c, b);

	LCS(m, n, A1, b);


	printf("\n长度为：%d \n\n", c[m][n]);
	//cout<<endl<<"长度为："<<c[m-1][n-1]<<endl;

	printf(" Matrix c is \n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n1; j++) {
			printf(" %d", c[i][j]);
		}
		printf("\n");
	}

	printf(" Matrix b is \n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n1; j++) {
			printf(" %d", b[i][j]);
		}
		printf("\n");
	}

	/* for ( i = 0; i<m1; i++)
	 {
		 delete []c[i];
		 delete []b[i];
	 }*/
	delete[]c;
	delete[]b;

	return 1;
}
