//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int fact(int n)
    {
        return (n==0) || (n==1) ? 1 : n*fact(n-1);
    }
    
    string kthPermutation(int n, int k)
    {
        // code here
        string s = "123456789";
        
        string num = s.substr(0,n);
        
        string ans = "";
        
        k = k-1;
        
        int cnt = n-1;
        
        while(ans.size()!=n)
        {
            int ind = k/fact(cnt);
            
            ans += num[ind];
            
            num.erase(ind,1);
            
            k = k%fact(cnt);
            
            cnt--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends