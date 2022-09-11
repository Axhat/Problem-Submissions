class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int n : nums)
        {
            pq.push(n);
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            int top = pq.top();
            
            ans.push_back(top);
            
            pq.pop();
        }
        
        return ans;
    }
};