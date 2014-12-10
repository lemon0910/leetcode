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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(NULL == head)
    		return head;
        ListNode *prev, *temp;
        int flag;

        prev = NULL;
        temp = head;

        while(temp)
        {
        	flag = 0;
        	 while(temp->next && temp->val == temp->next->val)
        	 {
        	 	flag = 1;
        	 	temp->next = temp->next->next;
        	 }

        	 if(flag)
        	 {
        	 	if(NULL == prev)
        	 	{
        	 		head = temp->next;
        	 		temp = temp->next;
        	 	}
        	 	else
        	 	{
        	 		prev->next = temp->next;
        	 		//prev = prev->next;
        	 		temp = temp->next;
        	 	}
        	 }
        	 else
        	 {
        	 	prev = temp;
        	 	temp = temp->next;
        	 }
        }

        return head;
    }
};