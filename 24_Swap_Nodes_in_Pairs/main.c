#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

/*

����˼·

�Ƚϳ�����������������濴һ�µ����������Ҫ����������A->B->C->D�е�B��C��Ҫ�����²�����

��Aָ��C
��Bָ��D
��Cָ��B
��ͷ�ڵ�֮ǰ��һ���ٽڵ�Ϳ���ʹ���еĽ�������������������


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
