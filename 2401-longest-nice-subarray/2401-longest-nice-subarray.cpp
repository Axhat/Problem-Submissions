class Solution {
public:
    
    bool isValid(vector<int>& bits)
    {
        for(int i=0;i<=31;i++)
        {
            if(bits[i]>1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        
        vector<int> bits(32,0);
        
        int start = 0;
        
        int end = 0;
        
        int n = nums.size();
        
        int ans = 0;
        
        while(end<n)
        {
            for(int i=0;i<=31;i++)
            {
                if(nums[end] & (1<<i))
                {
                    bits[i]++;
                }
            }
            
            while(!isValid(bits))
            {
                for(int i=0;i<=31;i++)
                {
                    if(nums[start] & (1<<i))
                    {
                        bits[i]--;
                    }
                }
                start++;
            }
            
//             for(auto b : bits)
//             {
//                 cout<<b<<" ";
//             }
            
//             cout<<"\n";
            
            ans = max(ans,end - start + 1);
            
            
            end++;
        }
        //cout<<"\n";
        
        return ans;
    }
};