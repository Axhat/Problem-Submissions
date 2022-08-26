class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //two cases what if
        //the number is the starting 
        //the number is in the between
        
        int ans = 0;
        
        unordered_set<int> st;
        
        // the iterations are to be done for the numbers 
        // which are at the starting
        
        for(int n : nums)
        {
            st.insert(n);
        }
        
        for(int n : nums)
        {
            if(st.find(n-1)==st.end())
            {
                int currentStreak = 1;
                
                int num = n+1;
                
                while(st.find(num)!=st.end())
                {
                    num++;
                    currentStreak++;
                }
                
                ans = max(ans,currentStreak);
            }
        }
        
        
        return ans;
    }
};