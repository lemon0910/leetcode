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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(0 == preorder.size())
            return nullptr;

        int index = 0;
        TreeNode *root = dfs(preorder, index, inorder, 0, inorder.size() - 1);

        return root;
    }

    TreeNode* dfs(vector<int> &preorder, int &index, vector<int> &inorder, int start, int end)
    {
        if(start > end)
            return nullptr;
        if(start == end)
        {
            TreeNode *p = new TreeNode(preorder[index++]);
            return p;
        }

        TreeNode *root = new TreeNode(preorder[index]);

        int mid;
        for(int i = start; i <= end; ++i)
        {
            if(preorder[index] == inorder[i])
            {
                mid = i;
                break;
            }
        }

        index++;
        root->left = dfs(preorder, index, inorder, start, mid - 1);
        root->right = dfs(preorder, index, inorder, mid + 1, end);

        return root;
    }
};