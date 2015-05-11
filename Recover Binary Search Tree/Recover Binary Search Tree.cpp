class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *n1 = NULL;
        TreeNode *n2 = NULL;
        TreeNode *prev = NULL;
        dfs(root, n1, n2, prev);

        if(n1 != NULL && n2 != NULL)
        {
            int tmp=n2->val;
            n2->val=n1->val;
            n1->val=tmp;
        }
    }
    void dfs(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev)
    {
        if(root == NULL) return;

        dfs(root->left,n1,n2,prev);
        if(prev != NULL && prev->val > root->val)
        {
            n2 = root;
            if(n1 == NULL)
            {
                n1=prev;
            }
        }
        prev = root;
        dfs(root->right, n1, n2, prev);
    }
};