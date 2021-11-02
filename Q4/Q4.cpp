// nQueen.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//n ºóÎÊÌâ


#include<stdio.h>
#include <math.h>
#define N 100

class Queen {
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(void);
	int n, * x;
	long sum;
};
/*¹¦ÄÜ£ºÅÐ¶Ïº¯Êý£¬ÅÐ¶ÏµÚk¸ö»ÊºóÊÇ·ñ¿ÉÒÔ·ÅÔÚÄ³Ò»¸öÎ»ÖÃ¡£
  ÊäÈë£ºµÚk¸ö»Êºó¡£
  Êä³ö£ºÈç¹ûÓëÖ®Ç°µÄ»Êºó³öÏÖÔÚÍ¬Ò»ÁÐ»òÍ¬Ò»¶Ô½ÇÏßÔò·ÅÖÃÊ§°Ü£¬·µ»Ø0£¬·ñÔò·µ1¡£*/

bool Queen::Place(int k)
{
	int i;
	for (i = 1; i < k; i++)
		if (abs(k - i) == abs(x[k] - x[i]) || x[k] == x[i])
			return false;
	return true;
}

void  Queen::Backtrack(void)
{
	x[1] = 0;
	int k = 1;
	while (k > 0)
	{
		x[k] += 1;
		while ((x[k] <= n) && !(Place(k)))
		{
			x[k] += 1;

			if (x[k] <= n)
			{
				if (k == n) { sum++; }
				else { k++; x[k] = 0; }
			}
			else { k--; }
		}
	}
}

/*
 ¹¦ÄÜ£ºÇó½â¿ÉÐÐ½âº¯Êý¡£µ±µÚt¸ö»Êºó¿ÉÒÔ·ÅÖÃÔÚtÐÐµÄÄ³Ò»Î»ÖÃÊ±£¬¼ÌÐø·ÅÖÃÏÂÒ»»Êºó£¬Ö±µ½  ËùÓÐ»Êºó·ÅÖÃ½áÊø£¬Èç¹ûÄ³Ò»»Êºó²»ÄÜ·ÅÖÃ£¬ÔòÒÆÏòÏÂÒ»ÁÐ·ÅÖÃ£¬Èç¹ûÕâÒ»ÁÐ¶¼²»ÄÜ·ÅÖÃ»òËùÓÐ»Êºó·ÅÖÃ½áÊø£¬·µ»ØÉÏÒ»»ÊºóÖØÐÂ·ÅÖÃ£¬×îÖÕ·µ»ØËùÓÐ¿ÉÐÐ½â¸öÊý¡£
 ÊäÈë£ºµÚt¸ö»Êºó¡£
 Êä³ö£º¿ÉÐÐ½â¸öÊý¡£
*/

int nQueen(int n)
{
	Queen X;
	X.n = n;
	X.sum = 0;
	int* p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0; //±êÃ÷µÚt¸ö»Êºó·ÅÔÚµÚiÁÐ   
	}
	X.x = p;
	X.Backtrack();

	delete[]p;
	printf("  \nThe number of solution is %d \n", X.sum);
	return X.sum;
}


int main(void)
{
	int n = 7;

	printf("Grid number n=%d\n", n);

	nQueen(n);


	scanf("%d", &n);

	return 1;
}