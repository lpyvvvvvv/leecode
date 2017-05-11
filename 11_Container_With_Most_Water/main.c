#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>


#define min(x, y) (((x) < (y)) ? (x): (y))

int maxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1;
	int h1, h2;
	int max = 0;
	int area = 0;
	while (i < j)
	{
		h1 = height[i];
		h2 = height[j];
		if (h1 < h2)
		{
			area = h1 * (j - i);
			i++;
		}
		else
		{
			area = h2 * (j - i);
			j--;
		}
		if (area > max)
			max = area;
	}
	return max;
}


int main()
{
	int a[10] = { 1,1 };
	int d = maxArea(a, 2);



	printf("%d\n", d);
	getchar();

	return 0;
}
