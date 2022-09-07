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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        //x and y coordinates 
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            TreeNode* node = t.first;
            int x = t.second.first;
            int y = t.second.second;
            m[x][y].insert(node->val);
            // x and y coordinates given to add and sort the numeber which has same row number and column number 
            
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        
        vector<vector<int>> ans;
        
        for(auto a : m)
        {
            vector<int> temp;
            for(auto b : a.second)
            {
                temp.insert(temp.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};