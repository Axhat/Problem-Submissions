class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[j]+=dp[j-1];
            }
        }
        return dp[m-1];
    }
};