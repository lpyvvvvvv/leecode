#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>




char** letterCombinations(char* digits, int* returnSize) {

	if (digits == NULL || !*digits)
	{
		*returnSize = 0;
		return NULL;
	}
	int digits_len = strlen(digits);
	char* digits_map[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int *len_map = malloc(sizeof(int)*digits_len);
	int *idx_map = malloc(sizeof(int)*digits_len);
	int i;
	int total_count = 1;
	for (i = 0; i < digits_len; i++)
	{
		
		int tmp_len = strlen(digits_map[digits[i] - 48]);
		total_count *= tmp_len;
		len_map[i] = tmp_len;
		idx_map[i] = 0;
	}
	int complete = 0;
	*returnSize = 0;
	
	char** ret = malloc(sizeof(char*)*total_count);
	
	while (1)
	{
		char* str = malloc(sizeof(int)*(digits_len + 1));
		for (i = 0; i < digits_len; i++)
		{
			int idx = idx_map[i];
			printf("%d %d\n", i, idx);
			str[i] = digits_map[digits[i] - 48][idx];
		}
		str[i] = '\0';
		ret[*returnSize] = str;
		*returnSize += 1;

		int last_idx = digits_len - 1;
		do {
			idx_map[last_idx] += 1;

			if (idx_map[last_idx] >= len_map[last_idx] )
			{
				idx_map[last_idx] = 0;
				last_idx = last_idx - 1;
				if (last_idx < 0)
				{
					complete = 1;
					break;
				}
			}
			else {
				break;
			}
		} while (1);
		if (complete)
			break;
	}
	free(len_map);
	free(idx_map);
	return ret;



}

int main()
{



	char* digits = "22";
	int returnSize = 0;

	letterCombinations(digits, &returnSize);
	


	getchar();

	return 0;
}
