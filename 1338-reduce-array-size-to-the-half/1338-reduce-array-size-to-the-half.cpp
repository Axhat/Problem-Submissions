class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> um;
        
        for(int a : arr)
        {
            um[a]++;
        }
        
        vector<pair<int,int>> v;
        
        for(auto m : um)
        {
            v.push_back({m.first,m.second});
        }
        
        sort(v.begin(),v.end(),[](const pair<int,int>& p1,const pair<int,int>& p2){return p1.second>p2.second;});
        
        // for(auto p : v)
        // {
        //     cout<<p.first<<" "<<p.second<<"\n";
        // }
        
        int sum = 0;
        int cnt = 0;
        
        while(sum<arr.size()/2)
        {
            sum+=v[cnt].second;
            cnt++;
        }
        return cnt;
        
    }
};