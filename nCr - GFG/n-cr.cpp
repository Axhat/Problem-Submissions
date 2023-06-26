//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    

    
    int util(vector<vector<int>>& dp,int n,int r)
    {
        if(r>n)
        {
            return 0;
        }else if(r==0 || r==n)
        {
            return 1;
        }
        
        if(dp[n][r]!=-1)
        {
            return dp[n][r];
        }
        
        return dp[n][r] = (((util(dp,n-1,r-1))%mod + (util(dp,n-1,r))%mod)%mod);
    }
    
    int nCr(int n, int r){
        // code here
       
        
        vector<vector<int>> dp(n+1,vector<int> (r+1,-1));
        
        return util(dp,n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends