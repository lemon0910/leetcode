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
    int minDepth(TreeNode *root) {
        if(0 == root)
            return 0;

        int ret = 0;
        dfs(root, 0, ret);

        return ret;
    }

    void dfs(TreeNode *root, int step, int &ret)
    {
        if(nullptr == root)
            return;

        step += 1;

        if(nullptr == root->left && nullptr == root->right)
        {
            if(0 == ret)
                ret = step;
            else
                ret = min(ret, step);
        }

        dfs(root->left, step, ret);
        dfs(root->right, step, ret);
    }
};