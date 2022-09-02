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
    
    //maintain the greatest value in the path
    //compare and increase the value of it
    
    void util(TreeNode* root,int& cnt,int mx)
    {
        if(root->val>=mx)
        {
            cnt++;
            mx = root->val;    
        }
        
        if(root->left)
        {
            util(root->left,cnt,mx);
        }
            
        if(root->right)
        {
            util(root->right,cnt,mx);
        }
        
    }
    
    int goodNodes(TreeNode* root) {
        
        if(!root)
        {
            return 0;
        }
        
        int cnt = 0;
        
        util(root,cnt,root->val);
        
        return cnt;
    }
};