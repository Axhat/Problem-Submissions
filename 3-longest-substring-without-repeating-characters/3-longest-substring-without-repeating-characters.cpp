class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int i = 0;
        int j = 0;
        
        unordered_map<char,int> um;
        
        int ans = 0;
        
        while(j<n)
        {
            if(um[s[j]]==0)
            {
                um[s[j]]++;
                
                ans = max(ans,j-i+1);
                
                j++;
                
            }else{
                um[s[i]]--;
                
                i++;
            }
        }
        
        return ans;
    }
};