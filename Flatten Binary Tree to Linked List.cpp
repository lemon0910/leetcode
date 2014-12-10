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
	void flatten(TreeNode *root) {
		if (nullptr == root)
			return;

		TreeNode *last;
		dfs(root, last);

	}

	void dfs(TreeNode *start, TreeNode* &last)
	{
		if (nullptr == start)
			return;

		if (nullptr == start->left && nullptr == start->right)
		{
			last = start;
			return;
		}

		TreeNode *left = start->left;
		TreeNode *right = start->right;

		start->left = nullptr;
		start->right = nullptr;

		TreeNode *llast = nullptr;
		dfs(left, llast);
		if (nullptr != llast)
			start->right = left;
		else
			start->right = right;

		TreeNode *rlast = nullptr;
		dfs(right, rlast);
		if (rlast != nullptr)
		{
			if (llast != nullptr)
				llast->right = right;
		}

		if(nullptr != rlast)
			last = rlast;
		else if(nullptr != llast)
			last = llast;
	}
};