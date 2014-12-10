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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        ListNode *l = l1;
        ListNode *r = l2;
        ListNode *p = &head;
        for(; l != nullptr && r != nullptr;)
        {
        	if(l->val > r->val)
        	{
        		p->next = r;
        		r = r->next;
        	}
        	else
        	{
        		p->next = l;
        		l = l->next;
        	}

        	p = p->next;
        }

        if(l)
        	p->next = l;
        else
        	p->next = r;

        return head.next;
    }
};