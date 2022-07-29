class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,char> mp,pm;
            int flag = 1;
            for(int j=0;j<words[i].size();j++)
            {
                if(mp.find(words[i][j])==mp.end() && pm.find(pattern[j])==pm.end())
                {
                    mp[words[i][j]] = pattern[j];
                    pm[pattern[j]] = words[i][j];
                }else if(mp[words[i][j]] != pattern[j] || pm[pattern[j]] != words[i][j]){
                    flag = 0;
                    break;
                }
            }
            
            // for(auto m : mp)
            // {
            //     cout<<m.first<<" "<<m.second<<"\n";
            // }
            // for(auto p : pm)
            // {
            //     cout<<p.first<<" "<<p.second<<"\n";
            // }
            if(flag)
            {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};