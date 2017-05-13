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


int** threeSum2(int* nums, int numsSize, int* returnSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;
	int** rs = NULL;

	for (int i = 0; i < numsSize - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int target = 0 - nums[i];
		int l = i + 1;
		int r = numsSize - 1;
		while (l < r)
		{
			int sum = nums[l] + nums[r];
			if (sum < target)
			{
				l++;
			}
			else if (sum > target)
			{
				r--;
			}
			else
			{
				*returnSize += 1;
				rs = realloc(rs, *returnSize * sizeof(int*));
				rs[*returnSize - 1] = (int*)malloc(3 * sizeof(int));
				rs[*returnSize - 1][0] = nums[i];
				rs[*returnSize - 1][1] = nums[l];
				rs[*returnSize - 1][2] = nums[r];
				l++;
				while (nums[l] == nums[l - 1])
				{
					l++;
				}
			}
		}
	}
	return rs;
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
	if (numsSize == 3 && nums[0] + nums[1] + nums[2] == 0)
	{
		*returnSize = 1;
		int** ret = malloc(sizeof(int*) * 1);
		int* p = malloc(3 * sizeof(int));
		p[0] = nums[0];
		p[1] = nums[1];
		p[2] = nums[2];
		ret[0] = p;
		return ret;
	}
		

	qsort(nums, numsSize, sizeof(int), cmp);
	int len = 100;
	int** ret = malloc(sizeof(int*) * len);
	int i;
	int size = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		int j = i + 1, k = numsSize - 1;
		while (j < k)
		{
			int n = nums[i] + nums[j] + nums[k];
			if (n == 0)
			{
				
				int* p = malloc(3 * sizeof(int));
				p[0] = nums[i];
				p[1] = nums[j];
				p[2] = nums[k];
				ret[size++] = p;

				if (size >= len)
				{
					len = len * 2;
					ret = realloc(ret, sizeof(int*) * len);
				}
				while(++j < k && nums[j] == nums[j - 1]) {}
				while (--k > j && nums[j] == nums[j - 1]) {}
			}
			else if (n < 0)
			{
				++j;
			}
			else
			{
				--k;
			}
		}
	}
	*returnSize = size;
	return ret;
}

int main()
{



	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int returnSize = 0;

	int i = sizeof(nums);

	int** ret = threeSum(nums, 6, &returnSize);
	//printf("%s\n", ret);

	
	getchar();

	return 0;
}
