class Solution {
public:
    
    int check(string s,string word)
    {
        int i=0;
        int j=0;
        
        while(i<s.size() && j<word.size())
        {
            if(s[i]==word[j])
            {
                i++;
                j++;
            }else{
                i++;
            }
        }
        
        if(j==word.size())
        {
            return true;
        }
        
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = words.size();
        
        unordered_map<string,int> mp;
        
        for(auto w : words)
        {
            mp[w]++;
        }
        
        int count = 0;
        
        for(auto m : mp)
        {
            if(check(s,m.first))
            {
                count+=m.second;
            }
        }
        
        return count;
    }
};