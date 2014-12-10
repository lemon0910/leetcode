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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *ret = head;

        int carry = 0;
        while(l1 || l2)
        {
        	int num = carry;
        	if(l1)
        	{
        		num += l1->val;
        		l1 = l1->next;
        	}
        	if(l2)
        	{
        		num += l2->val;
        		l2 = l2->next;
        	}
        	carry = num / 10;
        	num %= 10;
        	ListNode *temp = new ListNode(num);
        	ret->next = temp;
        	ret = temp;
        }

        if(carry)
        {
        	ListNode *temp = new ListNode(carry);
        	ret->next = temp;
        }

        return head->next;
    }
};