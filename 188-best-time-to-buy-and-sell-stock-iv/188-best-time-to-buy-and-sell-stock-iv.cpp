class Solution {
public:
    
    int util(int index,vector<int>& prices,int k,bool buy,vector<vector<vector<int>>>& dp)
    {
        if(index>=prices.size() || k<=0)
        {
            return 0;
        }
        
        if(dp[index][buy][k]!=-1) return dp[index][buy][k];
        
        int profit;
        
        if(buy==false)
        {
            profit = max(util(index+1,prices,k,false,dp),-prices[index] + util(index+1,prices,k,true,dp));
        }else{
        //if not bought
            profit = max(util(index+1,prices,k,true,dp),prices[index] + util(index+1,prices,k-1,false,dp));
        }
        
        return dp[index][buy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        // at most k transactions 
        
        //profit = buy - sell
        
        int profit = 0;
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
        
        return util(0,prices,k,false,dp);

    }
};