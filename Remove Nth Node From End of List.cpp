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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(NULL == head)
    		return NULL;

        ListNode *p, *q;
        q = head;
        int step = n;
        while(step--)
        {
        	q = q->next;
        }

        if(q == NULL)
        	return head->next;

        p = head;
        while(q && q->next)
        {
        	p = p->next;
        	q = q->next;
        }

        p->next = p->next->next;

        return head;
    }
};