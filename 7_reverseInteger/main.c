#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>



int reverse2(int x) {
	int rev = 0;

	while (x) {
		if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
			return 0;
		rev = rev * 10 + x % 10;
		x /= 10;
	}

	return rev;

}




int reverse(int n) {
	int i = 0, j = 0, p = 0;
	int x = 0;
	long num = 0;
	int a[12] = {0};
	int negative = 0;
	if (n < 0)
	{
		x = -n;
		negative = 1;
	}
	else
	{
		x = n;
	}

	for (; x > 0; j++)
	{
	
		i = x % 10;
		x = x / 10;
		a[p++] = i;
	}
	
	for (i = 0, p = 0; i < j; i++)
	{
		num += a[p++] * pow(10, j - i - 1);
	}

	if (negative)
	{
		num = -num;
	}
	if (num > INT_MAX)
	{
		return 0;
	}
	else if (num < INT_MIN)
	{
		return 0;
	}
	else
	{
		return num;
	}


	

}




int main()
{

	int ret = reverse2(-123);


	printf("%d\n", ret);
	getchar();

	return 0;
}
