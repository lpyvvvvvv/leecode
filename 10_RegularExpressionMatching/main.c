#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isMatch2(char* s, char* p) {
	size_t slen = strlen(s);
	size_t plen = strlen(p);
	size_t i, j;
	//int dp* [2] = malloc((slen + 1)*(slen + 1)*sizeof(int));

	bool **dp;
	int x;
	dp = (bool**)malloc(sizeof(bool*) * (slen + 1));//为二维数组分配3行
	for (x = 0; x < (slen + 1); ++x) {//为每列分配4个大小空间
		dp[x] = (bool*)malloc(sizeof(bool) * (slen + 1));
	}



	for (i = 0; i < slen + 1; i++)
	{
		for (j = 0; j < plen + 1; j++)
		{
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for (i = 0; i < plen; i++)
	{
		if (i > 0)
			if (p[i] == '*' && dp[0][i - 1])
			{
				dp[0][i + 1] = true;
			}
	}
	for (i = 0; i < slen; i++)
	{
		for (j = 0; j < plen; j++)
		{
			if (p[j] == '.')
				dp[i + 1][j + 1] = dp[i][j];
			if (p[j] == s[i])
				dp[i + 1][j + 1] = dp[i][j];
			if (p[j] == '*')
			{
				if (j > 0)
					if (p[j - 1] != s[i] && p[j - 1] != '.')
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					else
						dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
			}
		}
	}
	return dp[slen][plen];
}


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
	bool d = isMatch2("aaa", "a*");



	printf("%d\n", d);
	getchar();

	return 0;
}
