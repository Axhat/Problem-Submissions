class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> v;
        unordered_map<char,char> u;
        
        if(s.size()!=t.size())
        {
            return false;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if((v.find(s[i]-'a')==v.end() && u.find(t[i]-'a')==u.end())|| (v[s[i]-'a']==t[i] && u[t[i]-'a']==s[i]))
            {
                v[s[i]-'a'] = t[i];
                u[t[i]-'a'] = s[i];
            }else{
                return false;
            }
        }
        
//         for(auto x : v)
//         {
//             cout<<x<<" ";
//         }
        
//         cout<<"\n";
        
//         for(auto x : u)
//         {
//             cout<<x<<" ";
//         }
        
//         cout<<"\n";
        
        return true;
    }
};