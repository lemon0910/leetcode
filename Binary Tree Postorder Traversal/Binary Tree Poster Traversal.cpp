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
    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        return result;
    }
    
    void postorder(TreeNode *root)
    {
        if(nullptr == root)
            return;
        if(nullptr == root->left && nullptr == root->right)
        {
            result.push_back(root->val);
            return;
        }
        
        postorder(root->left);
        postorder(root->right);
        result.push_back(root->val);
    }
    
private:
    vector<int> result;
};
