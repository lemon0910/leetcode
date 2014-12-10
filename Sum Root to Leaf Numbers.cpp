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
    int sumNumbers(TreeNode *root) {
        if(nullptr == root)
        	return 0;

        vector<int> leaf;

        dfs(root, leaf, 0);

        int ret = 0;
        for(int i = 0; i < leaf.size(); ++i)
        	ret += leaf[i];

        return ret;
    }

    void dfs(TreeNode *root, vector<int> &leaf, int val)
    {
    	if(nullptr == root)
    		return;

    	val = val * 10 + root->val;

    	if(nullptr == root->left && nullptr == root->right)
    	{
    		leaf.push_back(val);
    		return;
    	}

    	dfs(root->left, leaf, val);
    	dfs(root->right, leaf, val);
    }
};