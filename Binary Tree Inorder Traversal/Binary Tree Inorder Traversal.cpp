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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);

        return ret;
    }

    void dfs(TreeNode *p, vector<int> &ans)
    {
        if(NULL == p)
            return;
        if(NULL != p->left)
            dfs(p->left, ans);

        ans.push_back(p->val);

        if(NULL != p->right)
            dfs(p->right, ans);
    }
};