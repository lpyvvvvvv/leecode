#include <stdio.h>
#include <stdlib.h>
#include <string.h>






char* longestPalindrome(char* s) {

	int i,j;
	int k;
	int maxlen = 1;
	int start_idx = 0, end_idx = 0;
	char *ret;
	int* pd;
	int n = strlen(s);

	if(s==NULL||!*s)
	{
		return "";
	}
	if(n==1)
	{
		return s;
	}


	pd = (int*)malloc(n*n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i >= j)
			{
				pd[i*n + j] = 1;
			}else
			{
				pd[i*n + j] = 0;
			}
			
		}
	}

	
	for(k=1;k<n;k++)
	{
		for(i=0;k+i<n;i++)
		{
			j = i+k;
			if(s[i] != s[j])
			{
				pd[i*n + j] = 0;
			}else{
				pd[i*n + j] = pd[(i+1)*n + j - 1];
				if(pd[i*n + j])
				{
					if(k+1>maxlen)
					{
						maxlen = k + 1;
						start_idx = i;
						end_idx = j;
					}

				}
			}
		}
	}
	free(pd);

	ret = (char*)malloc((maxlen + 1) * sizeof(char));
	memset(ret, 0, (maxlen + 1));
	memcpy(ret, s + start_idx, maxlen);
	return ret;


}












int main()
{




	char* s = "abcda";
	char* ret = longestPalindrome(s);
	printf("%s\n", ret);
	getchar();

	return 0;
}
