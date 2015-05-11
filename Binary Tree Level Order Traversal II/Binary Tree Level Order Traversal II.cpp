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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (NULL == root)
            return ret;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> ans;
            int n = q.size();
            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if (NULL != temp->left)
                    q.push(temp->left);
                if (NULL != temp->right)
                    q.push(temp->right);
            }
            ret.push_back(ans);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};