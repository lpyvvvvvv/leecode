#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>




int removeDuplicates2(int* nums, int numsSize) {
	if (numsSize <= 1) return numsSize;
	int len = 1, last = nums[0];
	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] != last) {
			last = nums[i];
			nums[len++] = nums[i];
		}
	}
	return len;
}


int removeDuplicates(int* nums, int numsSize) {
	int i, j, k;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] != nums[j])
				break;
		}
		if (i + 1 == j)
			continue;
		k = j;
		for (int n = 1; n + k - 1 < numsSize; n++)
		{
			nums[i + n] = nums[k + n - 1];
		}
		numsSize = numsSize - (j - i - 1);
	}
	return numsSize;
}



int main()
{



	int nums[] = { 1,1,2,3,1 };
	int numsSize = sizeof(nums) / sizeof(int);
	int returnSize = removeDuplicates2(nums, numsSize);

	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", nums[i]);
	}

	getchar();

	return 0;
}
