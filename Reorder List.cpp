/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        	return;

        ListNode *fastp = head;
        ListNode *lowp = head;
        ListNode *tail = nullptr;

        while(fastp != nullptr && fastp->next != nullptr)
        {
            tail = lowp;
            fastp = fastp->next->next;
            lowp = lowp->next;
        }

        tail->next = nullptr; 
        reverseList(lowp);
        fastp = head;
        tail = nullptr;

        while(fastp != nullptr)
        {
            ListNode *tmp = lowp->next;
            lowp->next = fastp->next;
            fastp->next = lowp;
            tail = lowp;
            fastp = lowp->next;
            lowp = tmp;
        }

        if(lowp != nullptr)
            tail->next = lowp;

    }
    void reverseList(ListNode* &head)
    {
        if(head == nullptr || head->next == nullptr)
        	return;

        ListNode *pre = head;
        ListNode *p = pre->next;
        while(p != nullptr)
        {
            ListNode *tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        
        head->next = nullptr;
        head = pre;
    }
};