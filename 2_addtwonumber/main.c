#include <stdio.h>
#include <stdlib.h>
#include <math.h>





struct ListNode {
	int val;
	struct ListNode *next;
	
};




struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {


	struct ListNode* h1 = l1;
	struct ListNode* h2 = l2;

	struct ListNode* head = NULL;

	struct ListNode* last = NULL;

	struct ListNode* p = NULL;

	int x;
	int v1, v2;
	int up = 0;
	while (1)
	{
		if (h1)
		{
			v1 = h1->val;
			h1 = h1->next;
		}
			
		
		if (h2)
		{
			v2 = h2->val;
			h2 = h2->next;
		}
			
		x = v1 + v2 + up;
		v1 = 0;
		v2 = 0;
		
		if (!up)
		{
			p = (struct ListNode*)malloc(sizeof(struct ListNode));
		}
		

		p->val = x >= 10 ? x - 10 : x;
		p->next = NULL;

		if (!head)
		{
			head = p;
		}


		if (x >= 10)
		{
			up = 1;

			if (last)
			{
				last->next = p;
			}
			last = p;
			p = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->val = up;
			p->next = NULL;

			last->next = p;
			continue;
		}
		else {
			
			if (!up)
			{
				
				if (last)
				{
					last->next = p;
				}
				
				last = p;

				
			}
			else {
				last = p;
			}



			up = 0;
		}


		if (!h1 && !h2)
			break;
	
		
	}

	return head;


}






int main()
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	//struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	//struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));


	p1->val = 9;
	p1->next = NULL;

	//p2->val = 4;
	//p2->next = p3;

	//p3->val = 3;
	//p3->next = NULL;


	struct ListNode* q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q8 = (struct ListNode*)malloc(sizeof(struct ListNode));


	q1->val = 1;
	q1->next = q2;

	q2->val = 9;
	q2->next = q3;

	q3->val = 8;
	q3->next = q4;

	q4->val = 9;
	q4->next = NULL;
	/*
	q5->val = 8;
	q5->next = q6;

	q6->val = 9;
	q6->next = q7;

	q7->val = 9;
	q7->next = q8;

	q8->val = 9;
	q8->next = NULL;
	*/

	struct ListNode* m = addTwoNumbers(p1, q1);
	while (m)
	{
		printf("%d ", m->val);
		m = m->next;
	}



	getchar();

	return 0;
}
