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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size();
        if(0 == len)
            return nullptr;

        TreeNode *ret = dfs(num, 0, len - 1);

        return ret;
    }

    TreeNode *dfs(vector<int> &num, int start, int end)
    {
        if(start > end)
        {
            return nullptr;
        }

        if(start == end)
        {
            TreeNode *p = new TreeNode(num[start]);
            return p;
        }

        int mid = (start + end) / 2;

        TreeNode *lret = dfs(num, start, mid - 1);
        TreeNode *rret = dfs(num, mid + 1, end);

        TreeNode *p = new TreeNode(num[mid]);
        p->left = lret;
        p->right = rret;

        return p;
    }
};