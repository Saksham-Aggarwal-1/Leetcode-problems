/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool empty = false;
        if(!root)
            return true;
        q.push(root);
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                TreeNode *tempnode = q.front();
                q.pop();
                
                if(!tempnode->left)
                    empty = true;
                else
                {
                    if(empty)
                        return false;
                    else
                        q.push(tempnode->left);
                }
                
                if(!tempnode->right)
                    empty = true;
                else
                {
                    if(empty)
                        return false;
                    else
                        q.push(tempnode->right);
                }
                
            }
        }
        
        return true;
    }
};