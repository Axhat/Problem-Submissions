class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& grid,int n,int m)
    {
        if(i==n)
        {
            return j;
        }
        
        if(grid[i][j]==1 && j+1<m && grid[i][j+1]==1)
        {
            return solve(i+1,j+1,grid,n,m);
        }
        
        if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1)
        {
            return solve(i+1,j-1,grid,n,m);
        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m,1);
        
        for(int i=0;i<m;i++)
        {
            ans[i] = solve(0,i,grid,n,m);
        }
        
        return ans;
    }
};