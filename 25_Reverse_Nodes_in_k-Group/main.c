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

struct ListNode* reverseList(struct ListNode* head, int k) {

	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = cur->next;

	while (cur && k>0)
	{
		k--;
		cur->next = pre;

		pre = cur;
		cur = next;
		if (!cur)
			break;
		next = next->next;
	}
	return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode helper = { 0 };
	helper.next = head;

	struct ListNode* pre = &helper;
	struct ListNode* cur = head;

	struct ListNode* node1 = NULL;
	struct ListNode* node2 = cur;

	int i = 0, j;
	while (1)
	{

		for (j = 0; j < k; j++)
		{
			if (!node2)
			{
				i = 1;
				break;
			}
			node2 = node2->next;
		}
		if (i)
			break;
		node1 = reverseList(cur, k);

		pre->next = node1;
		cur->next = node2;
	

		pre = cur;
		cur = node2;


	}
	return helper.next;
}



struct ListNode* swapPairs(struct ListNode* head) {

	struct ListNode helper = { 0 };
	helper.next = head;

	struct ListNode* pre = &helper;
	struct ListNode* cur = head;
	struct ListNode* node1 = NULL;
	struct ListNode* node2 = NULL;

 	while (cur && cur->next)
	{
		node1 = cur->next;
		node2 = cur->next->next;
		pre->next = node1;
		cur->next = node2;
		node1->next = cur;

		pre = cur;
		cur = node2;
		
		
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



	struct ListNode* ret = reverseKGroup(p1, 3);

	getchar();

	return 0;
}
