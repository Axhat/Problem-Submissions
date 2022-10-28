class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> um;
        
        for(string s : strs)
        {
            string x = s;
            
            sort(x.begin(),x.end());
            
            um[x].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto m : um)
        {
            vector<string> v;
            
            for(auto s : m.second)
            {
                v.push_back(s);
            }
            
            ans.push_back(v);
        }
          
        return ans;
        
    }
};