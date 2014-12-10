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
    ListNode *insertionSortList(ListNode *head) {
        int flag = 1;
        while(flag)
        {
        	flag = 0;
        	ListNode *p = head;
        	while(NULL != p && NULL != p->next)
        	{
        		if(p->val > p->next->val)
        		{
        			int temp = p->val;
        			p->val = p->next->val;
        			p->next->val = temp;
        			flag = 1;
        		}
        		p = p->next;
        	}
        }

        return head;
    }
};