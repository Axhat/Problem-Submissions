//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        int i = 1;
        int j = N;
        
        while(i<j)
        {
            for(int it=0;it<k;it++)
            {
                i++;
                if(i==j)
                {
                    break;
                }
            }
            
            for(int it=0;it<k;it++)
            {
                j--;
                if(i==j)
                {
                    break;
                }
            }
        }
        
        return i;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends