#include <iostream>
using namespace std;

const int L = 11;

int RecurMatrixChain(int i, int j, int** s, int* p);//递归求最优解
void Traceback(int i, int j, int** s);//构造最优解

int main()
{
	int p[L] = { 300,35,105,5,10,2007,25,50,50,200,25 };

	int** s = new int* [L];
	for (int i = 0; i < L; i++)
	{
		s[i] = new int[L];
	}
	cout << "  " << L-1 << "  个矩阵:" << endl;
	for (int i = 1; i < L; i++) {
		cout << "  " << p[i - 1] << "x" << p[i];
	}
	cout << endl;
	cout << "矩阵的最少计算次数为：" << RecurMatrixChain(1, 6, s, p) << endl;
	cout << "矩阵最优计算次序为：" << endl;
	Traceback(1, 6, s);
	return 0;
}

int RecurMatrixChain(int i, int j, int** s, int* p)
{
	if (i == j) return 0;
	int u = RecurMatrixChain(i, i, s, p) + RecurMatrixChain(i + 1, j, s, p) + p[i - 1] * p[i] * p[j];
	s[i][j] = i;

	for (int k = i + 1; k < j; k++)
	{
		int t = RecurMatrixChain(i, k, s, p) + RecurMatrixChain(k + 1, j, s, p) + p[i - 1] * p[k] * p[j];
		if (t < u)
		{
			u = t;
			s[i][j] = k;
		}
	}
	return u;
}

void Traceback(int i, int j, int** s)
{
	if (i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << " and A" << (s[i][j] + 1) << "," << j << endl;
}
