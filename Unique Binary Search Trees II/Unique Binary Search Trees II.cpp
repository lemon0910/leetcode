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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(0 == n)
        {
            ret.push_back(nullptr);
            return ret;
        }

        ret = buildTree(1, n);

        return ret;
    }

    vector<TreeNode*> buildTree(int start, int end)
    {
        vector<TreeNode*> ret;
        if(start > end)
            return ret;
        if(start == end)
        {
            TreeNode *p = new TreeNode(start);
            ret.push_back(p);
            return ret;
        }

        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode*> lret = buildTree(start, i - 1);
            vector<TreeNode*> rret = buildTree(i + 1, end);

            if(lret.empty() && rret.empty())
            {
                ret.push_back(new TreeNode(i));
                continue;
            }

            if(lret.empty())
            {
                for(int j = 0; j < rret.size(); ++j)
                {
                    TreeNode *p = new TreeNode(i);
                    p->right = rret[j];
                    ret.push_back(p);
                }
                continue;
            }

            if(rret.empty())
            {
                for(int j = 0; j < lret.size(); ++j)
                {
                    TreeNode *p = new TreeNode(i);
                    p->left = lret[j];
                    ret.push_back(p);
                }
                continue;
            }

            for(int j = 0; j < lret.size(); ++j)
            {
                for(int k = 0; k < rret.size(); ++k)
                {
                    TreeNode *p = new TreeNode(i);
                    p->left = lret[j];
                    p->right = rret[k];

                    ret.push_back(p);
                }
            }
        }
        return ret;
    }
};