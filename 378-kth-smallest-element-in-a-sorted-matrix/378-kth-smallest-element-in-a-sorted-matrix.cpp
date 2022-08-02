class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //second approach
        
        int l = matrix[0][0];
        
        int n = matrix.size();
        
        int r = matrix[n-1][n-1];
        
        int count;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            
            count = 0;
            
            for(int i=0;i<n;i++)
            {
                count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            
            if(count<k){
                l = mid+1; 
            }else{
                r = mid;
            }
            
        }
        
        return l;
    }
};