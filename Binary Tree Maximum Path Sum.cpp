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
    int maxPathSum(TreeNode *root) {
        if(nullptr == root)
        	return 0;

        int ret = root->val;
        int single = 0;

        dfs(root, single, ret);

        return ret;
    }

    void dfs(TreeNode *root, int &single, int &ret)
    {
    	if(nullptr == root)
    		return;

    	if(nullptr == root->left && nullptr == root->right)
    	{
    		single = max(root->val, 0);
    		ret = max(ret, root->val);
    		return;
    	}

    	int lsingle = 0;
    	int rsingle = 0;

    	dfs(root->left, lsingle, ret);
    	dfs(root->right, rsingle, ret);

    	single = max(max(lsingle, rsingle) + root->val, 0);
    	ret = max(ret, lsingle + rsingle + root->val);
    }
};