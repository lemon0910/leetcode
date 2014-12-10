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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        vector<int> temp;

        dfs(root, temp, ret, sum, 0);
        return ret;
    }

    void dfs(TreeNode *root, vector<int> temp, vector<vector<int> > &ret, const int sum, int val)
    {
    	if(nullptr == root)
    		return;

    	val += root->val;
    	temp.push_back(root->val);

    	if(nullptr == root->left && nullptr == root->right)
    	{
    		if(sum == val)
    		{
    			ret.push_back(temp);
    		}

    		return;
    	}

    	dfs(root->left, temp, ret, sum, val);
    	dfs(root->right, temp, ret, sum, val);
    }
};