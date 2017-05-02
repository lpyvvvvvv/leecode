#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {
	int i, j;
	int v1, v2;
	for (i = 0; i<numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			v1 = *(nums + i);
			v2 = *(nums + j);
			if (v1 + v2 == target)
			{
				int* p = (int*)malloc(2 * sizeof(int));
				*p = i;
				*(p + 1) = j;
				return p;
			}
		}
	}
	return NULL;
}




}






int main()
{


	getchar();

	return 0;
}
