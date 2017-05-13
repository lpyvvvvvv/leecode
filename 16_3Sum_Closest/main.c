#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int threeSumClosest(int* nums, int numsSize, int target) {

	qsort(nums, numsSize, sizeof(int), cmp);

	int ret = 0;
	int assign = 0;
	for (int i = 0; i < numsSize - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		int l = i + 1;
		int r = numsSize - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (!assign) {
				ret = sum;
				assign = 1;
			}
			else {
				if (abs(sum - target) < abs(ret - target))
					ret = sum;
			}


			if (sum < target)
			{
				l++;
			}
			else if (sum > target)
			{
				r--;
			}
			else {
				return sum;
			}
		}

	}
	return ret;

}

int main()
{



	int nums[] = { -1, 2, 1, -4 };


	int size = sizeof(nums) / sizeof(int);

	int ret = threeSumClosest(nums, size, 1);
	printf("%d\n", ret);


	getchar();

	return 0;
}
