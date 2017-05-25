#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>







int removeElement(int* nums, int numsSize, int val) {
	int len = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] != val) {
			nums[len++] = nums[i];
		}
	}
	return len;
}


int main()
{



	int nums[] = { 3,2,2,3,1 };
	int numsSize = sizeof(nums) / sizeof(int);
	int returnSize = removeElement(nums, numsSize, 3);

	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", nums[i]);
	}

	getchar();

	return 0;
}
