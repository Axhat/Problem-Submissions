class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=nums.size()-3;i>=0;i--)
        {
            if(nums[i]+nums[i+1]>nums[i+2])
            {
                return nums[i+2]+nums[i+1]+nums[i];
            }
        }
        
        return 0;
    }
};