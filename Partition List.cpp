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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less, *more, *pl, *pm;
        less = more = pl = pm = NULL;

        while(head)
        {
        	ListNode *temp = head;
        	head = head->next;
        	if(x > temp->val)
        	{
        		if(less == NULL)
        			less = pl = temp;
        		else
        		{
        			pl->next = temp;
        			pl = temp;
        		}
        	}
        	else
        	{
        		if(more == NULL)
        			more = pm = temp;
        		else
        		{
        			pm->next = temp;
        			pm = temp;
        		}
        	}
        }

        if(pl)
        	pl->next = more;
        if(pm)
        	pm->next = NULL;

        if(NULL == less)
        	return more;
        else
        	return less;
    }
};