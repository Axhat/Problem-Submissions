class Solution {
public:
    
    int maximumSubarraySumNoLargerThanK(vector<int>& v,int target)
    {
        int n = v.size();
        
        int maxi = INT_MIN;
        
        int curr_sum = 0;
        
        set<int> st;
        
        //for the case where curr_sum == k
        st.insert(0);
        
        for(auto x : v)
        {
            curr_sum+=x;
            
            auto it = st.lower_bound(curr_sum-target);
            
            if(it!=st.end())
            {
                maxi = max(maxi,curr_sum - *it);
            }
            
            st.insert(curr_sum);
        }
        
        return maxi;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxi = INT_MIN;
        
        //Going the way from top to bottom
        
        for(int i=0;i<n;i++)
        {
            vector<int> prefi(m,0);
            
            for(int k=i;k<n;k++)
            {
                for(int j=0;j<m;j++)
                {
                    prefi[j]+=matrix[k][j];
                }
                
                maxi = max(maxi,maximumSubarraySumNoLargerThanK(prefi,target));
            }
        }
        
        return maxi;
    }
};