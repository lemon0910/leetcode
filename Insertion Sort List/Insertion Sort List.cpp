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
        if(nullptr == head)
            return nullptr;

        ListNode *pos = head;
        while(pos)
        {
            ListNode *tmp = pos->next;
            ListNode *minpos = pos;
            while(tmp)
            {
                if(tmp->val < minpos->val)
                    minpos = tmp;
                tmp = tmp->next;
            }

            //swap(pos->val, minpos->val);  swap问题，当pos和minpos相同时不能够使用
            int v = pos->val;
            pos->val = minpos->val;
            minpos->val = v;
            pos = pos->next;
        }

        return head;
    }
};
