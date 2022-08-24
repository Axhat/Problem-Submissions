class Solution {
public:
    
    int m = 1e9+7;
    
    int numTilings(int n) {
        
        int dp[n+1];
        
        dp[0] = 0;
        
        dp[1] = 1;
        if(n>=2)
        {
            dp[2] = 2;
        }
        
        if(n>=3)
        {
            dp[3] = 5;
        }
        
        for(int i=4;i<=n;i++)
        {
            dp[i] = (2*dp[i-1]%m+dp[i-3]%m)%m;
            //cout<<dp[i]<<"\n";
        }
        
        return dp[n];
    }
};