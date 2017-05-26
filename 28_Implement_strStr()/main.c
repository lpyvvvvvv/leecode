#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>







int strStr(char* haystack, char* needle) {
	if (!*haystack && !*needle)
		return 0;
	if (!*needle)
		return 0;
	int len = strlen(haystack);
	int len_needle = strlen(needle);
	int match = 0, ret = -1, n = 0;
	for (int i = 0; i < len - len_needle + 1; i++)
	{
		match = 1;
		for (int j=0; j < len_needle;j++)
		{
			if (haystack[i + j] != needle[j])
			{
				match = 0;
				break;
			}
		}
		if (match)
			return i;
	}
	return ret;
}




int main()
{
	int idx = strStr("mississippi", "issip");

	getchar();

	return 0;
}
