class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        queue<int> q;
        
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        
        while(--n)
        {
            int sz = q.size();
            
            while(sz--)
            {
                int top = q.front();
                
                int last_digit = top%10;
                
                q.pop();
                
                if(last_digit-k>=0) q.push(top*10 + last_digit - k);
                
                if(k && last_digit+k<=9) q.push(top*10 + last_digit + k);
            }
        }
        
        while(!q.empty())
        {
            int top = q.front();
            
            ans.push_back(top);
            
            q.pop();
        }
        
        return ans;
    }
};