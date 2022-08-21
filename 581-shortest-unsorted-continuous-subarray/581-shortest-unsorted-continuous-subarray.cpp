class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        //find the smallest number 
        //find the largest number 
        //make them go the places they are meant to be on 
        
        int mx = nums[0];
        
        int end = -1;
        
        for(int i=1;i<n;i++)
        {
            if(mx>nums[i])
            {
                end = i;
            }else{
                mx = nums[i];
            }
        }
        
        int start = 0;
        
        int mn = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(mn<nums[i])
            {
                start = i;
            }else{
                mn = nums[i];
            }
        }
        
        return end - start + 1;
    }
};