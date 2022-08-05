class Solution {
public:
    
    int dp[1001];
    
    int util(vector<int>& nums,int target)
    {
        //if(nums.size()==index) return 0;
        if(target<0) return 0;
        
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        //start from the every index and find all their combinations 
        //array is not sorted
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans += util(nums,target-nums[i]);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        return util(nums,target);
        
    }
};