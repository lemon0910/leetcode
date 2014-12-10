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
    bool isSymmetric(TreeNode *root) {
        if(nullptr == root)
        	return true;

        bool flag = true;
        dfs(root->left, root->right, flag);

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
    		flag = false;
    		return;
    	}

    	dfs(p->left, q->right, flag);
    	dfs(p->right, q->left, flag);
    }
};