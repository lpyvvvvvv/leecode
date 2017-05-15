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


struct ListNode* removeNthFromEnd2(struct ListNode* head, int n) {
	struct ListNode **t1, *t2;
	t1 = &head;
	t2 = head;
	int i;

	for (i = 1; i < n; i++)
		t2 = t2->next;

	while (t2->next) {
		t1 = &((*t1)->next);
		t2 = t2->next;
	}
	*t1 = (*t1)->next;
	return head;

}




struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (head == NULL)
		return NULL;
	
	struct ListNode* ret = head, *node = head;

	int array_len = 100;
	struct ListNode** tmp_array = malloc(sizeof(struct ListNode*)*array_len);

	int i = 0;
	tmp_array[i] = head;
	while (node->next)
	{
		i++;

		if (i >= array_len)
		{
			array_len = array_len * 2;
			tmp_array = realloc(tmp_array, sizeof(struct ListNode*)*array_len);
		}

		node = node->next;
		tmp_array[i] = node;
	}

	if (n == i + 1)
	{
		ret = head->next;
		free(head);
	}
	else if (n == 1)
	{
		tmp_array[i - 1]->next = NULL;
		free(tmp_array[i]);
	}
	else
	{
		int last_idx = i - n;
		int next_idx = i - n + 2;
		tmp_array[last_idx]->next = tmp_array[next_idx];
		free(tmp_array[i - n + 1]);
	}

	free(tmp_array);
	return ret;
}

int main()
{



	struct ListNode* head = malloc(sizeof(struct ListNode));
	struct ListNode* p1 = malloc(sizeof(struct ListNode));
	struct ListNode* p2 = malloc(sizeof(struct ListNode));
	struct ListNode* p3 = malloc(sizeof(struct ListNode));
	struct ListNode* p4 = malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = p1;

	p1->val = 2;
	p1->next = p2;

	p2->val = 3;
	p2->next = p3;

	p3->val = 4;
	p3->next = p4;

	p4->val = 5;
	p4->next = NULL;



	struct ListNode* ret = removeNthFromEnd2(head, 2);
	


	getchar();

	return 0;
}
