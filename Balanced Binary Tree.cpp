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
    bool isBalanced(TreeNode *root) {
        if(nullptr == root)
        	return true;

        bool flag = true;
        int step = 0;
        dfs(root, step, flag);

        return flag;
    }

    void dfs(TreeNode *root, int &step, bool &flag)
    {
    	if(!flag)
    		return;

    	if(nullptr == root)
    		return;

    	int lstep = 0;
    	int rstep = 0;
    	step++;

    	dfs(root->left, lstep, flag);
    	dfs(root->right, rstep, flag);

    	if(abs(lstep - rstep) > 1)
    		flag = false;

    	step += max(lstep, rstep);
    }
};