class Solution {
public:
    
    int dp[100];
    
    int util(int ind,string s)
    {
        if(ind>=s.size())
        {
            return 1;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        if(s[ind]=='0')
        {
            return dp[ind] = 0;
        }
        
        int takeOne = util(ind+1,s);
        
        int takeTwo = 0;
        
        if(ind+1<s.size() && s[ind]=='1')
        {
            takeTwo = util(ind+2,s);
        }else if(ind+1<s.size() && s[ind]=='2' && s[ind+1]<='6')
        {
            takeTwo = util(ind+2,s);
        }
        
        return dp[ind] = takeOne + takeTwo;
    }
    
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        return util(0,s);
        
    }
};