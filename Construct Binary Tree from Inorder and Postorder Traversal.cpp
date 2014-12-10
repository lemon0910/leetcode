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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = nullptr;
        if(inorder.empty())
        	return root;

        int index = postorder.size() - 1;
        root = dfs(postorder, index, inorder, 0, inorder.size() - 1);

        return root;
    }

    TreeNode *dfs(vector<int> &postorder, int &index, vector<int> &inorder, int start, int end)
    {
    	if(start > end)
    		return nullptr;
    	if(start == end)
    	{
    		TreeNode *p = new TreeNode(postorder[index--]);
    		return p;
    	}

    	TreeNode *root = new TreeNode(postorder[index]);
    	int mid;

    	for(int i = start; i <= end; ++i)
    	{
    		if(postorder[index] == inorder[i])
    		{
    			mid = i;
    			break;
    		}
    	}

    	index--;
    	root->right = dfs(postorder, index, inorder, mid + 1, end);
    	root->left = dfs(postorder, index, inorder, start, mid - 1);

    	return root;
    }
};