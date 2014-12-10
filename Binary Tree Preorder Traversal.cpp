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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(nullptr == root)
        	return ret;

        dfs(root, ret);

        return ret;
    }

    void dfs(TreeNode *root, vector<int> &ret)
    {
    	if(nullptr == root)
    		return;

    	ret.push_back(root->val);
    	dfs(root->left, ret);
    	dfs(root->right, ret);
    }
};