#include <stdio.h>
#include <windows.h>

int acman(int m, int n) {
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return acman(m - 1, 1);
	else
		return acman(m - 1, acman(m, n - 1));
}

int main() {
	int a = 0;
	a = acman(2, 5);
	printf("%d", a);
	return 0;
}