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
    ListNode *sortList(ListNode *head) {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode *fast = nullptr;
        ListNode *slow = nullptr;
        fast = slow = head;
        //关键步骤，注意{1,2}两个元素的时候如何进行切分，多了的话就不需要严格的切分成等长
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        //没有考虑返回值，导致re的错误，递归还是不熟悉
        fast = sortList(head);
        slow = sortList(slow);
        return merge(fast, slow);
    }

private:
    ListNode *merge(ListNode *l, ListNode *r)
    {
        if(nullptr == l)
            return r;
        if(nullptr == r)
            return l;

        ListNode *head = nullptr;
        if(l->val < r->val)
        {
            head = l;
            l = l->next;
        }
        else
        {
            head = r;
            r = r->next;
        }

        ListNode *temp = head;
        while(l && r)
        {
            if(l->val < r->val)
            {
                temp->next = l;
                l = l->next;
            }
            else
            {
                temp->next = r;
                r = r->next;
            }
            temp = temp->next;
        }

        temp->next = nullptr;
        if(l)
            temp->next = l;
        if(r)
            temp->next = r;

        return head;
    }
};
