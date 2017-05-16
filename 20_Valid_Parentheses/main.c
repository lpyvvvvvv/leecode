#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


bool isValid(char* s) {
	int stack_len = 100;
	char* stack = malloc(sizeof(char)*stack_len);
	int stack_idx = 0;
	for (int i = 0; s[i]; i++)
	{
		char c = s[i];
		if (c == '[' || c == '{' || c == '(')
		{
			stack[stack_idx++] = c;
			if (stack_idx >= stack_len)
			{
				stack_len *= 2;
				stack = realloc(stack, sizeof(char)*stack_len);
			}

		}
		else if (c == ']' || c == '}' || c == ')')
		{
			char last_c;
			if (stack_idx > 0)
				last_c = stack[--stack_idx];
			else
				return false;
			switch (last_c)
			{
			case '[':
				if (c != ']')
					return false;
				break;
			case '{':
				if (c != '}')
					return false;
				break;
			case '(':
				if (c != ')')
					return false;
				break;
			default:
				return false;
				break;
			}
		}
	}
	if (stack_idx != 0)
		return false;
	else
		return true;

}

int main()
{





	char* str = "{}";
	bool ret = isValid(str);
	


	getchar();

	return 0;
}
