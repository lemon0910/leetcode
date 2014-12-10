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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(NULL == head)
			return NULL;

		int flag = 1;
		vector<ListNode*> pv;

		ListNode *pNode = head;
		while(pNode)
		{
			if(flag >= m && flag <= n)
			{
				pv.push_back(pNode);
			}

			if(flag > n)
				break;

			flag++;
			pNode = pNode->next;
		}

		int len = pv.size();
		for(int i = 0, j = len - 1; i < j; ++i, --j)
		{
			swap(pv[i]->val, pv[j]->val);
		}

		return head;
	}
};