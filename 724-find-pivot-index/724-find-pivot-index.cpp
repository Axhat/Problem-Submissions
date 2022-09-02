class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total_sum = nums[0];
        
        vector<int> pref(nums);
        
        for(int i=1;i<nums.size();i++)
        {
            total_sum+=nums[i];
            pref[i]+=pref[i-1];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(total_sum==pref[i])
            {
                return i;
            }
            total_sum-=nums[i];
        }
        
        return -1;
    }
};