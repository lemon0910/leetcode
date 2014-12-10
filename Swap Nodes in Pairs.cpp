/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode temp(0);
        temp.next = head;

        ListNode *p = &temp;
        while(p->next && p->next->next)
        {
        	ListNode *q1, *q2;
        	q1 = p->next;
        	q2 = p->next->next;
        	p->next = q2;
        	q1->next = q2->next;
        	q2->next = q1;
        	p = q1;
        }

        return temp.next;
    }
};