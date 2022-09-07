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
    
    void util(TreeNode* root,string& ans)
    {
        if(!root)
        {
            return;
        }
        
        ans+=to_string(root->val);
        
        if(root->left)
        {
            ans+='(';
            util(root->left,ans);
            ans+=')';
        }else if(root->right)
        {
            ans+="()";
        }
        
        if(root->right)
        {
            ans+='(';
            util(root->right,ans);
            ans+=')';
        }
    }
    
    string tree2str(TreeNode* root) {
        
        string ans = "";
        
        util(root,ans);
        
        return ans;
        
    }
};