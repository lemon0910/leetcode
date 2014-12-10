/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(nullptr == head)
        	return nullptr;

        int len = 0;
        ListNode *p = head;
        while(p)
        {
        	p = p->next;
        	len++;
        }

        TreeNode *ret = dfs(head, 0, len - 1);

        return ret;
    }

    TreeNode *dfs(ListNode* &head, int start, int end)
    {
    	if(start > end)
    		return nullptr;

    	int mid = (start + end) / 2;
    	TreeNode *lret = dfs(head, start, mid - 1);
    	TreeNode *root = new TreeNode(head->val);
    	root->left = lret;
    	head = head->next;
    	root->right = dfs(head, mid + 1, end);

    	return root;
    }
};