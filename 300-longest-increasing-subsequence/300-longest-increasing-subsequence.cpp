class Solution {
public:
    
    //tabulation method 
    //Overlapping sub problem solutions are to be saved here 
    // in the LIS array
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int lis[n];
        
        lis[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            lis[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && lis[j]+1>lis[i])
                {
                    lis[i] = lis[j] +1;
                }
            }
        }
        
        return *max_element(lis,lis+n);
    }
};