#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

/*
�����ַ� ��Ӧ�İ��������ֱ�ʾΪ
I V X  L  C   D   M
1 5 10 50 100 500 1000

��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
С�����֣����� I��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
����ʹ��ʱ����д�������ظ����ó������Σ�
��һ���������滭һ�����ߡ���ʾ��������� 1000 ����
*/


int romanToInt(char* s) {
	if (!*s || s == NULL)
		return 0;
	char c;
	char next;
	int ret = 0;
	int i;
	for (i=0;s[i];i++)
	{
		c = s[i];
		next = s[i + 1];
		switch (c)
		{
		case 'I':

			if (next)
			{
				if (next == 'V')
				{
					ret += 4;
					i++;
					break;
				}
				else if (next == 'X')
				{
					ret += 9;
					i++;
					break;
				}
					
			}
			ret += 1;
			break;
		case 'V':
			ret += 5;
			break;
		case 'X':
			if (next)
			{
				if (next == 'L')
				{
					ret += 40;
					i++;
					break;
				}
				else if (next == 'C')
				{
					ret += 90;
					i++;
					break;
				}

			}
			ret += 10;
			break;
		case 'L':
			ret += 50;
			break;
		case 'C':
			
			if (next)
			{
				if (next == 'D')
				{
					ret += 400;
					i++;
					break;
				}
				else if (next == 'M')
				{
					ret += 900;
					i++;
					break;
				}

			}
			ret += 100;
			break;
		case 'D':
			ret += 500;
			break;
		case 'M':
			ret += 1000;
			break;
		default:
			break;
		}
	}
	return ret;
}




char* intToRoman(int num) {
	char* ret = malloc(120 * sizeof(char));
	memset(ret, 0, 120 * sizeof(char));

	int n2 = num;
	while (n2 > 0) {
		int i = 1;
		int n = n2;
		while (n / 10 > 0)
		{
			n = n / 10;
			i *= 10;
		}
		char a, b, c;
		switch (i)
		{
		case 1:
			a = 'I';
			b = 'V';
			c = 'X';
			break;
		case 10:
			a = 'X';
			b = 'L';
			c = 'C';
			break;
		case 100:
			a = 'C';
			b = 'D';
			c = 'M';
			break;
		case 1000:
			a = 'M';
			b = ' ';
			c = ' ';
			break;

		default:
			break;
		}
		char str[20] = { 0 };

		switch (n)
		{
		case 1:
			sprintf(str, "%c", a);
			break;
		case 2:
			sprintf(str, "%c%c", a, a);
			break;
		case 3:
			sprintf(str, "%c%c%c", a, a, a);
			break;
		case 4:
			sprintf(str, "%c%c", a, b);
			break;
		case 5:
			sprintf(str, "%c", b);
			break;
		case 6:
			sprintf(str, "%c%c", b, a);
			break;
		case 7:
			sprintf(str, "%c%c%c", b, a, a);
			break;
		case 8:
			sprintf(str, "%c%c%c%c", b, a, a, a);
			break;
		case 9:
			sprintf(str, "%c%c", a, c);
			break;
		default:
			break;
		}

		n2 = n2 % i;

		strcat(ret, str);
	}

	return ret;

}

void test_ptr(char *s)
{
	s++;
}


int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i < 4000; i++)
	{
		char* str = intToRoman(i);
		j = romanToInt(str);
		printf("%s %d %d\n", str, i, j);
		assert(i == j);
		free(str);
	}
	




	
	getchar();

	return 0;
}
