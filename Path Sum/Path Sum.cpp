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
    bool hasPathSum(TreeNode *root, int sum) {
        bool ret = false;
        dfs(root, ret, sum, 0);

        return ret;
    }

    void dfs(TreeNode *root, bool &ret, int sum, int val)
    {
        if(ret)
            return;

        if(nullptr == root)
            return;

        val += root->val;

        if(nullptr == root->left && nullptr == root->right)
        {
            if(val == sum)
            {
                ret = true;
                return;
            }
        }

        dfs(root->left, ret, sum, val);
        dfs(root->right, ret, sum, val);
    }
};