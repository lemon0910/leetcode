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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back = head;
        for(int i = 0; i < n - 1; ++i)
        {
            if(back == NULL)
                break;
            back = back->next;
        }

        if(back == NULL)
            return head;

        if(back->next == NULL)
            return head->next;

        back = back->next;
        ListNode* prev = head;
        while(back->next != NULL)
        {
            back = back->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};
