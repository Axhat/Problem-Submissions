class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        //min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.rbegin(),v.rend());
        
        long long int ans = 0;
        
        long long int totalSpeed = 0;
        
        for(int i=0;i<n;i++)
        {
            int curEff = v[i].first;
            int curSpeed = v[i].second;
            
            if(pq.size()==k)
            {
                totalSpeed-=pq.top();
                pq.pop();
            }
            
            pq.push(curSpeed);
            
            totalSpeed += curSpeed;
            
            ans = max(ans,(totalSpeed*curEff));
        }
        
        return ans%1000000007;
    }
};