#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i = 0, j = 0, k = 0;
	int a, b;
	int m = 0, n = 0;
	double ret;
	int sum = nums1Size + nums2Size;
	int* temp = (int*)malloc(sizeof(int)*sum);
	while (k < sum)
	{
		if (i < nums1Size)
		{
			a = *(nums1 + i);
			m = 1;
		}
		if (j < nums2Size)
		{
			b = *(nums2 + j);
			n = 1;
		}
		if (m == 1 && n == 1)
		{
			if (a <= b)
			{
				*(temp + k) = a;
				i++;
			}
			else {
				*(temp + k) = b;
				j++;
			}
		}
		else if (m == 1)
		{
			*(temp + k) = a;
			i++;
		}
		else if (n == 1)
		{
			*(temp + k) = b;
			j++;
		}
		
		m = 0, n = 0;
		k++;

	}
	if (sum % 2 == 0)
	{
		a = *(temp + sum / 2);
		b = *(temp + sum / 2 - 1);
		ret = (a + b) / 2.0;
	}
	else {
		ret =  *(temp + (sum + 1) / 2 - 1);
	}
	free(temp);
	return ret;

}














int lengthOfLongestSubstring(char* s) {
	unsigned int letter_idx[256];
	char* p = s;
	unsigned int last_idx = 0;
	unsigned int substr_len = 0;
	unsigned int start_idx = 0;
	unsigned int max_len = 0;
	char c;

	memset(letter_idx, 0, sizeof(letter_idx));
	while (p != NULL && *p != 0) {
		c = *p;
		last_idx = letter_idx[c];
		letter_idx[c] = p - s + 1;
		substr_len++;
		if (last_idx > start_idx) {
			substr_len = substr_len - (last_idx - start_idx);
			start_idx = last_idx;
		}
		if (substr_len > max_len) {
			max_len = substr_len;
		}
		p++;
	}
	return max_len;


}




int main()
{

	int a[] = { 1,2 };
	int b[] = { 3,4 };
	double ret = findMedianSortedArrays(a, sizeof(a)/sizeof(int), b, sizeof(b) / sizeof(int));
	printf("%f\n", ret);
	getchar();

	return 0;
}
