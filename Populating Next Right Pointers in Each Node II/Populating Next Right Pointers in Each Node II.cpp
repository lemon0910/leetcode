/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(nullptr == root)
        	return;

        queue<TreeLinkNode*> q;
        q.push(root);

        while(!q.empty())
        {
        	int len = q.size();
        	while(len--)
        	{
        		TreeLinkNode *temp = q.front();
        		q.pop();
        		if(!len)
        			temp->next = nullptr;
        		else
        			temp->next = q.front();

        		if(temp->left)
        			q.push(temp->left);
        		if(temp->right)
        			q.push(temp->right);

        	}
        }
    }
};