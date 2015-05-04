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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode temp(0);
        temp.next = head;
        ListNode *p = &temp;
        vector<ListNode*> arr(k);

        while(p)
        {
        	ListNode *q = p->next;
        	arr.clear();
        	for(int i = 0; i < k; ++i)
        	{
        		if(q)
        		{
        			arr.push_back(q);
        			q = q->next;
        		}
        		else
        		{
        			return temp.next;
        		}
        	}

        	ListNode *last = arr[k - 1]->next;
        	q = p;
        	for(int i = k - 1; i >= 0; --i)
        	{
        		q->next = arr[i];
        		q = arr[i];
        	}

        	p = arr[0];
        	p->next = last;
        }

        return temp.next;
    }
};