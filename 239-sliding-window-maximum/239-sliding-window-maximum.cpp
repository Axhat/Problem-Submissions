class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        multiset<int> mst;
        
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            mst.insert(nums[i]);
        }
        
        ans.push_back(*mst.rbegin());
        
        for(int i=k;i<n;i++)
        {
            mst.insert(nums[i]);
            
            auto itr = mst.find(nums[i-k]);
            
            //cout<<*itr<<"\n";
            
            mst.erase(itr);
            
            ans.push_back(*mst.rbegin());
        }
        
        return ans;
        
    }
};