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
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    
public:
    void inorder(TreeNode* root)
    {
        if(root->left)
            inorder(root->left);
        
        if(root->val < prev->val && first == NULL)
        {
            first = prev;
            middle = root;
        }
        else if(root->val < prev->val)
        {
            last = root;
        }
        prev = root;
        
        if(root->right)
            inorder(root->right);
            
    }
    
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
        return;
    }
};