#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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


int main()
{
	
	char* str = intToRoman(3999);



	printf("%s\n", str);
	getchar();

	return 0;
}
