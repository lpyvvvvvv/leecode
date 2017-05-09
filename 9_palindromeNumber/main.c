#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>



bool isPalindrome2(int x) {
	int s = 0, y;

	if (x<0)
		return 0;
	y = abs(x);
	x = y;
	while (x != 0)
	{

		s = s * 10 + x % 10;
		x = x / 10;
	}

	return s == y;

}


bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	int n1 = x, n2;
	int k = 0;
	int i = 0;
	int v1 = 0, v2 = 0;
	while (n1 > 0)
	{
		n1 /= 10;
		k++;
	}
	for (i = 0, n1 = x, n2 = x; i < k; i++)
	{
		v2 = n2 / pow(10, k - i - 1);
		n2 = n2 % (int)pow(10, k - i - 1);
		v1 = n1 % 10;
		n1 = n1 / 10;
		if (v1 != v2)
			return false;
		if (n1 == n2)
			break;
	}
	return true;
}



int main()
{
	bool d = isPalindrome(1231);



	printf("%d\n", d);
	getchar();

	return 0;
}
