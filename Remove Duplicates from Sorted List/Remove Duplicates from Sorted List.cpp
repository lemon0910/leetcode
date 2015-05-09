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

        ListNode *temp = head;
        while(temp)
        {
            while(temp->next && temp->next->val == temp->val)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }

        return head;
    }
};