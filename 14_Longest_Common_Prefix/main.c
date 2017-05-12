#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


char* longestCommonPrefix2(char** strs, int strsSize) {
	int length = 0;
	char* commonPrefix = "";
	int ptr;
	bool stop = false;
	int i;
	char cur;

	if (strsSize == 0) {
		return commonPrefix;
	}

	ptr = 0;
	while (1) {
		cur = strs[0][ptr];
		if (cur == '\0') {
			if (ptr != 0) {
				break;
			}
			else {
				return commonPrefix;
			}
		}
		for (i = 1; i<strsSize; i++) {
			if (strs[i][ptr] == '\0' || cur != strs[i][ptr]) {
				stop = true;
				break;
			}
		}
		if (stop == true) {
			if (ptr == 0) {
				return commonPrefix;
			}
			break;
		}
		ptr++;
	}
	commonPrefix = (char*)malloc(sizeof(char) * (ptr + 1));
	commonPrefix[ptr] = '\0';
	for (i = 0; i<ptr; i++) {
		commonPrefix[i] = strs[0][i];
	}

	return commonPrefix;
}

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0)
		return "";
	if (strs == NULL)
		return "";
	int i = 0, j = 0;
	char *ret = malloc(200 * sizeof(char));
	char c;
	char *str0 = strs[0];
	if (str0 == NULL || !*str0)
		return "";
	char *str;
	int same = 1;
	while (1)
	{
		
		c = str0[i];
		if (!c)
			break;
		for (j = 1; j < strsSize; j++)
		{
			str = strs[j];
			if (str == NULL || !*str)
			{
				same = 0;
				break;
			}
			if (str[i] != c)
			{
				same = 0;
				break;
			}
		}
		if (!same)
			break;
		ret[i] = c;
		i++;
	}
	ret[i] = '\0';
	return ret;
}





int main()
{



	char* p[] = {
		"abab",
		"aba",
		""
	};
	

	char* ret = longestCommonPrefix(p, 3);
	printf("%s\n", ret);

	
	getchar();

	return 0;
}
