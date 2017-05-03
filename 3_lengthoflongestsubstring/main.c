#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int lengthOfLongestSubstring(char* s) {
	int i = 0, j = 0;
	int start = 0, end = 0;
	int maxLen = 0;
	int len = 0;
	int same = 0;
	char temp;
	char c;


	if (*s == '\0')
		return 0;


	while (1)
	{
		end++;
		temp = *(s + end);

		for (j = start; j < end ; j++) {
			c = *(s + j);

			if(c == temp)
			{
				same = 1;
				break;
			}
		}

		len = end - start;
		if (len > maxLen)
		{
			maxLen = len;
		}

		if (same)
		{
			
			same = 0;

			start = j + 1;
		}


		if (temp == '\0')
			break;
	}
	return maxLen;


}




int main()
{

	char *s = "abcabcbb";
	int len = lengthOfLongestSubstring(s);
	printf("%d\n", len);
	getchar();

	return 0;
}
