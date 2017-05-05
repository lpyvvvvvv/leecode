#include <stdio.h>
#include <stdlib.h>
#include <string.h>






char* convert(char* s, int numRows) {
	int i = 0, j = 0;
	int idx = 0;
	int p = 0;
	if (numRows == 1)
		return s;
	int len = strlen(s);
	char* ret = (char*)malloc((len+1) * sizeof(char));
	
	for (i = 1; i <= numRows; i++)
	{
		j = 0;
		while (1)
		{
			idx = i + (2 * numRows - 2)*j;
			if (idx > len)
				break;
			ret[p++] = s[idx - 1];
			if (i > 1 && i < numRows)
			{
				idx = idx + (numRows - i) * 2;
				if (idx > len)
					break;
				ret[p++] = s[idx - 1];
			}
			j++;
		}
	}
	ret[p] = '\0';
	return ret;
}











int main()
{




	char* s = "A";
	char* ret = convert(s, 1);
	printf("%s\n", ret);
	getchar();

	return 0;
}
