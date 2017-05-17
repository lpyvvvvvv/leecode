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

struct ListNode *merge2list(struct ListNode *head1, struct ListNode*head2)
{
	struct ListNode node = { 0 };
	struct ListNode *res = &node;

	while (head1 && head2) {
		if (head1->val <= head2->val) {
			res->next = head1;
			head1 = head1->next;
		}
		else {
			res->next = head2;
			head2 = head2->next;
		}
		res = res->next;
	}

	if (head1)
		res->next = head1;
	else if (head2)
		res->next = head2;

	return node.next;
}



struct ListNode* mergeKLists2(struct ListNode** lists, int listsSize) {
	int i;

	if (listsSize == 0)
		return NULL;

	while (listsSize > 1) {
		int k = (listsSize + 1) / 2;

		for (i = 0; i < listsSize / 2; i++)
			printf("%d %d\n", i, i+k);
			lists[i] = merge2list(lists[i], lists[i + k]);

		listsSize = k;
	}
	return lists[0];
}









struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (listsSize == 0)
		return NULL;
	
	struct ListNode* root = malloc(sizeof(struct ListNode));

	root->val = 0;
	root->next = NULL;

	struct ListNode* cur_node = root;
	
	while (1)
	{
		struct ListNode* min_list = NULL;
		int min = INT_MAX;
		int min_idx = 0;
		int list_count = 0;
		for (int i = 0; i < listsSize; i++)
		{
			struct ListNode* list = lists[i];
			if (list)
			{
				if (list->val < min)
				{
					min = list->val;
					min_idx = i;
					
				}
				list_count++;
			}
			
		}
		if (list_count > 0)
		{
			min_list = lists[min_idx];

			cur_node->next = min_list;
			cur_node = min_list;
			lists[min_idx] = lists[min_idx]->next;
		}
		if (list_count <= 1)
			break;
	}
	struct ListNode* ret = root->next;
	free(root);
	return ret;

}

int main()
{
	struct ListNode* p1 = malloc(sizeof(struct ListNode));
	struct ListNode* p2 = malloc(sizeof(struct ListNode));
	struct ListNode* p3 = malloc(sizeof(struct ListNode));


	p1->val = 1;
	p1->next = NULL;
	p2->val = 10;
	p2->next = NULL;
	p3->val = 5;
	p3->next = NULL;


	int lists_size = 7;
	struct ListNode** lists = malloc(sizeof(struct ListNode*)*lists_size);
	lists[0] = p1;
	lists[1] = p2;
	lists[2] = p3;
	lists[3] = NULL;
	lists[4] = NULL;
	lists[5] = NULL;
	lists[6] = NULL;

	struct ListNode* ret = mergeKLists2(lists, lists_size);

	getchar();

	return 0;
}
