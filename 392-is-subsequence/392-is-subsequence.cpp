class Solution {
public:
    bool isSubsequence(string s, string t) {
        // two pointers
        
        int i=0; // one pointer for the first string
        
        int j=0; //second pointer for the second string
        
        int n = s.size();
        int m = t.size();
        
        if(n>m)
        {
            return false;
        }
        
        if(n==m)
        {
            return (s==t);
        }
        
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }else{
                j++;
            }
        }
        
        return (i==n);
    }
};