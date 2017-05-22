#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

/*

解题思路

比较常见的链表操作。下面看一下典型情况，如要交换链表中A->B->C->D中的B和C需要做如下操作：

将A指向C
将B指向D
将C指向B
在头节点之前加一个假节点就可以使所有的交换都符合上面的情况。


*/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	

	struct ListNode helper = { 0 };
	helper.next = head;

	struct ListNode* pre = &helper;
	struct ListNode* cur = head;
	struct ListNode* next = NULL;

 	while (cur && cur->next)
	{
		next = cur->next->next;
		cur->next->next = cur;
		pre->next = cur->next;
		if (next && next->next)
			cur->next = next->next;
		else
			cur->next = next;
		pre = cur;
		cur = next;


		
	}
	return helper.next;
}

int main()
{
	struct ListNode* p1 = malloc(sizeof(struct ListNode));
	struct ListNode* p2 = malloc(sizeof(struct ListNode));
	struct ListNode* p3 = malloc(sizeof(struct ListNode));
	struct ListNode* p4 = malloc(sizeof(struct ListNode));

	p1->val = 1;
	p1->next = p2;
	p2->val = 10;
	p2->next = p3;
	p3->val = 5;
	p3->next = p4;
	p4->val = 4;
	p4->next = NULL;



	struct ListNode* ret = swapPairs(p1);

	getchar();

	return 0;
}
