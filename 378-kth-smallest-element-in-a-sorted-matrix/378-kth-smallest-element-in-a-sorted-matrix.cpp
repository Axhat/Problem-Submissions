class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> m;
        
        int n = matrix.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                m.insert(matrix[i][j]);
            }
        }
        
        auto itr = m.begin();
        k--;
        while(k--)
        {
            itr++;
        }
        
        return *itr;
    }
};