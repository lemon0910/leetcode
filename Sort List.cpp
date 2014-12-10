/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        	return head;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        fast = sortList(head);
        slow = sortList(slow);
        return merge(fast,slow);
        
    }
 
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if(head1 == nullptr)
        	return head2;
        if(head2 == nullptr)
        	return head1;

        ListNode *res , *p ;
        if(head1->val < head2->val)
        {
        	res = head1; 
        	head1 = head1->next;
        }
        else
        {
        	res = head2; 
        	head2 = head2->next;
        }

        p = res;
        
        while(head1 != nullptr && head2 != nullptr)
        {
            if(head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != nullptr)
        	p->next = head1;
        else if(head2 != nullptr)
        	p->next = head2;

        return res;
    }
};