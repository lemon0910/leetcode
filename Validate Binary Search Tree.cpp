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
    bool isValidBST(TreeNode *root) {
        if(nullptr == root)
        	return true;

        bool ret = dfs(root, false, 0, false, 0);

        return ret;
    }

    bool dfs(TreeNode *root, bool lflag, int lval, bool rflag, int rval)
    {
    	if(nullptr == root)
    		return true;

    	if(lflag)
    	{
    		if(root->val <= lval)
    			return false;
    	}

    	if(rflag)
    	{
    		if(root->val >= rval)
    			return false;
    	}

    	if(root->left)
    	{
    		bool ans = dfs(root->left, lflag, lval, true, root->val);
    		if(!ans)
    			return false;
    	}

    	if(root->right)
    	{
    		bool ans = dfs(root->right, true, root->val, rflag, rval);
    		if(!ans)
    			return false;
    	}

    	return true;
    }
};