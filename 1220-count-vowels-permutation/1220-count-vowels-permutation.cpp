class Solution {
public:
    
    int mod = 1e9+7;
    
    int countVowelPermutation(int n) {
        
        //saving the possible strings of length in the variables
        long a = 1,e = 1,i = 1,o = 1,u =1;
        
        for(int j=2;j<=n;j++)
        {
            long a1 = a,e1 = e,i1 = i,o1 = o,u1 = u;
            
            a = e1;
            e = a1+i1;
            i = a1+e1+o1+u1;
            o = i1+u1;
            u = a1;
            
            a%=mod;
            e%=mod;
            i%=mod;
            o%=mod;
            u%=mod;
        }
        
        return (a+e+i+o+u)%mod;
    
    }
};