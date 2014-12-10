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
        preorder(root);
        return result;
    }
    
    void preorder(TreeNode *root)
    {
        if(nullptr == root)
            return;
        if(nullptr == root->left && nullptr == root->right)
        {
            result.push_back(root->val);
            return;
        }
        
        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
private:
    vector<int> result;
};
