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
		int carry = 0;
		ListNode *head = new ListNode(-1);
		ListNode *prev = head;
		while (l1 && l2)
		{
			int temp = l1->val + l2->val + carry;
			ListNode *newNode = new ListNode(temp % 10);
			carry = temp / 10;
			prev->next = newNode;
			prev = newNode;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			int temp = l1->val + carry;
			ListNode *newNode = new ListNode(temp % 10);
			carry = temp / 10;
			prev->next = newNode;
			prev = newNode;
			l1 = l1->next;
		}
		while (l2)
		{
			int temp = l2->val + carry;
			ListNode *newNode = new ListNode(temp % 10);
			carry = temp / 10;
			prev->next = newNode;
			prev = newNode;
			l2 = l2->next;
		}
		if (carry)
		{
			ListNode *newNode = new ListNode(carry);
			prev->next = newNode;
		}

		return head->next;
	}
};