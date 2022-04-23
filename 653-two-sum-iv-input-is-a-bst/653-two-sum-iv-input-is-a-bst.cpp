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
    void fill_array(vector<int> &v, TreeNode* root)
    {
        if(root->left)
            fill_array(v, root->left);
        v.push_back(root->val);
        if(root->right)
            fill_array(v, root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        fill_array(v, root);
        
        int i=0, j=v.size()-1;
        while(i<j)
        {
            int sum = v[i]+v[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};