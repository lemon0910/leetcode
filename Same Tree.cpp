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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool flag = true;
        dfs(p, q, flag);

        return flag;
    }

    void dfs(TreeNode *p, TreeNode *q, bool &flag)
    {
    	if(!flag)
    		return;
    	if(nullptr == p)
    	{
    		if(nullptr != q)
    			flag = false;

    		return;
    	}

    	if(nullptr == q)
    	{
    		flag = false;
    		return;
    	}

    	if(p->val != q->val)
    	{
    		flag =false;
    		return;
    	}

    	dfs(p->left, q->left, flag);
    	dfs(p->right, q->right, flag);
    }
};