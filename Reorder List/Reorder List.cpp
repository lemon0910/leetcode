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
    void reorderList(ListNode *head) {
        if(NULL == head || NULL == head->next || NULL == head->next->next)
            return;

        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *headA = head;
        ListNode *headB = slow->next;
        slow->next = NULL;
        ListNode *prev = headB, *cur = headB->next;
        prev->next = NULL;
        while(cur)
        {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
            if(!cur)
                headB = temp;
        }

        while(headA && headB)
        {
            ListNode *tempA = headA->next;
            ListNode *tempB = headB->next;
            headA->next = headB;
            headB->next = tempA;
            headA = tempA;
            headB = tempB;
        }
    }
};
