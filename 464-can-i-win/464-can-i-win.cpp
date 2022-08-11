class Solution {
public:
    
    // the total is to be used to subtracted with every step
    // game is being optimally - means we'll have to return true even if there's a single way to win 
    bool util(vector<int>& dp,int mask,int k,int x)
    {
        if(k<=0) return false;
        
        if(dp[mask]!=-1) return dp[mask];
        
        for(int i=1;i<=x;i++)
        {
            dp[mask] = false;
            if(!(mask&(1<<i)))
            {
                dp[mask] |= !util(dp,mask | (1<<i), k-i,x); // turn changes here the next player has to fail
                
                if(dp[mask]) return dp[mask] = true;
            }
        }
        
        return dp[mask] = false;
    }
    
    bool canIWin(int x, int k) {
        
        //x -> choices
        //k -> total
        if(k==0)
        {
            return true;
        }
        
        vector<int> dp((1<<x+1),-1);
        
        //edge case
        if(x*(x+1)/2<k) return false;
        
        int mask = 0;
        
        return util(dp,mask,k,x);
        
    }
};