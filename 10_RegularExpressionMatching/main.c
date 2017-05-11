#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>




bool isMatch(const char *s, const char *p)
{
	if (s == NULL || p == NULL) return false;
	if (*p == '\0') return *s == '\0';
	// ".*" matches "", so we can't check (*s == '\0') here.

	if (*(p + 1) == '*')
	{
		// Here *p != '\0', so this condition equals with
		// (*s != '\0' && (*p == '.' || *s == *p)).
		while ((*s != '\0' && *p == '.') || *s == *p)
		{
			if (isMatch(s, p + 2)) return true;
			++s;
		}

		return isMatch(s, p + 2);
	}
	else if ((*s != '\0' && *p == '.') || *s == *p)
	{
		return isMatch(s + 1, p + 1);
	}

	return false;
}



int main()
{
	bool d = isMatch("aab", ".*");



	printf("%d\n", d);
	getchar();

	return 0;
}
