class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        long long int val = 1;
        
        for(int r=0;r<=rowIndex;r++)
        {
            ans.push_back(val);
            
            val = val*(rowIndex - r)/(r+1);
        }
        
        return ans;
    }
};