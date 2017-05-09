#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>




int myAtoi(char* str) {
	int p = 0;
	long long rev = 0;
	int fix = 1;
	
	char c;
	if (str == NULL || !*str)
		return 0;
	

	for (; str[p] == ' '; p++);
	c = str[p];

	if (c < '0')
	{
		if (c != '-' && c != '+')
			return 0;
	}
	else if (c > '9')
	{
		return 0;
	}
		
	if (c == '-')
		fix = -1;
	else if( c == '+')
		fix = 1;
	else if( c == '0')
		fix = 1;
	else
		rev = c - 48;
	
	while (c = str[++p])
	{
		if (c < '0' || c > '9')
			break;
		rev = rev * 10 + (c - 48) * fix;
		if (rev > INT_MAX)
			return INT_MAX;
		else if (rev < INT_MIN)
			return INT_MIN;
	}

	return rev;
}


int main()
{
	int d = myAtoi("2147483648");



	printf("%d\n", d);
	getchar();

	return 0;
}
