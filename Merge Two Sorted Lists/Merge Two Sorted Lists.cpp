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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* go = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                go->next = l1;
                l1 = l1->next;
                go = go->next;
            }
            else
            {
                go->next = l2;
                l2 = l2->next;
                go = go->next;
            }
        }

        if(l1)
        {
            go->next = l1;
        }
        if(l2)
        {
            go->next = l2;
        }

        return head->next;
    }
};
