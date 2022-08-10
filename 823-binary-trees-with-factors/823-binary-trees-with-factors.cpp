class Solution {
public:
    
    int mod = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        long long ans = 0;
        
        unordered_map<long long,long long> um;
        
        for(int i=0;i<n;i++)
        {
            um[arr[i]]+=1;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int child1 = arr[j];
                    int child2 = arr[i]/arr[j];
                    
                    if(um.find(child2)!=um.end())
                    {
                        um[arr[i]] += (um[child1]*um[child2])%mod;
                        um[arr[i]] %= mod; 
                    }
                }
            }
            
            ans += um[arr[i]];
            ans %= mod;
        }
        
        return ans;
    }
};