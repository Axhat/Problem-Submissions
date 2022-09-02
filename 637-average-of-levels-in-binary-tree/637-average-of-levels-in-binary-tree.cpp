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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            
            long long int sum = 0;
            
            int n = sz;
            
            while(sz--)
            {
                TreeNode* top = q.front();
                
                q.pop();
                
                sum+=top->val;
                
                if(top->left)
                {
                    q.push(top->left);
                }
                
                if(top->right)
                {
                    q.push(top->right);
                }
                
            }
            
            ans.push_back((1.0*sum)/n);
            
        }
        
        return ans;
    }
};