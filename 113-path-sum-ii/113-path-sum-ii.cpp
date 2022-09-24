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
    
    void util(TreeNode* root,int targetSum,int sum,vector<int>& path,vector<vector<int>>& ans)
    {
        if(!root)
        {
            return;
        }
        
        sum+=root->val;
        
        path.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                ans.push_back(path);
                path.pop_back();
                return;
            }
            
            path.pop_back();
            return;
        }
        
        
            util(root->left,targetSum,sum,path,ans);
        
        
        
        util(root->right,targetSum,sum,path,ans);
        
        path.pop_back();

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        if(!root)
        {
            return ans;
        }
        
        vector<int> path;
        
        util(root,targetSum,0,path,ans);
        
        return ans;
    }
};