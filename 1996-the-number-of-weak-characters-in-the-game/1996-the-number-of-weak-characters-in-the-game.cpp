class Solution {
public:
    
    // going low to high for attacks
    // going high to low for defense
    // as both of them are to be evaluated differently
    
    static bool comp(vector<int>& a,vector<int>& b)
    {
        if(a[0]!=b[0])
        {
            return a[0]>b[0];
        }
        
        return a[1]<b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        
        sort(properties.begin(),properties.end(),comp);
        
        int maxi = INT_MIN; // the greatest defence as for to be comapred to be counted as a number
        
        int ans = 0;
        
        for(auto p : properties)
        {
            if(p[1]>=maxi)
            {
                maxi = max(p[1],maxi);
            }else{
                ans++;
            }
        }
        
        return ans;
    }
};