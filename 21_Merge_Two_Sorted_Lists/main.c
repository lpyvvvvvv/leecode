#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = NULL, *last = NULL, *tmp = NULL;
	if (l1 && l2 == NULL )
		return l1;
	else if (l2 && l1 == NULL)
		return l2;
	else if (l1 == NULL && l2 == NULL)
		return NULL;
	
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	last = head;
	while (l1 || l2)
	{
		if (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				last->next = l1;
				last = l1;
				l1 = l1->next;
			}
			else {
				last->next = l2;
				last = l2;
				l2 = l2->next;
			}
		}
		else if(l1)
		{
			last->next = l1;
			break;
		}
		else {
			last->next = l2;
			break;
		}
	}
	return head;
}

int main()
{

	struct ListNode* l1 = malloc(sizeof(struct ListNode));
	struct ListNode* l11 = malloc(sizeof(struct ListNode));



	struct ListNode* l2 = malloc(sizeof(struct ListNode));
	struct ListNode* l21 = malloc(sizeof(struct ListNode));





	l1->val = -9;
	l1->next = l11;

	l11->val = 3;
	l11->next = NULL;



	l2->val = 5;
	l2->next = l21;
	l21->val = 7;
	l21->next = NULL;






	struct ListNode* ret = mergeTwoLists(l1, l2);
	while (ret)
	{
		printf("%d\n", ret->val);
		ret = ret->next;
	}


	getchar();

	return 0;
}
