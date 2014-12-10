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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(NULL == headA || NULL == headB)
            return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *temp = NULL;
        ListNode *t = headA;
        while(t)
        {
            lenA++;
            if(t->next == NULL)
            {
                temp = t;
                break;
            }
            t = t->next;
        }
        t = headB;
        while(t)
        {
            lenB++;
            if(t->next == NULL)
            {
                if(temp == t)
                    break;
                else
                    return NULL;
            }
            t = t->next;
        }

        int len = abs(lenA - lenB);
        ListNode *tA = headA, *tB = headB;
        if(lenA < lenB)
        {
            while(len--)
            {
                tB = tB->next;
            }
        }
        else
        {
            if(len != 0)
                while(len--)
                {
                    tA = tA->next;
                }
        }

        while(tA != tB)
        {
            tA = tA->next;
            tB = tB->next;
        }

        return tA;
    }
};
