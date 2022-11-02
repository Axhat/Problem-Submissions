class Solution {
public:
    
    
    //dfs necessary as to know the which way the ball came out
    
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(i==n) return j;
        
        if(grid[i][j]==1 && j+1<m && grid[i][j+1]==1)
        {
            return dfs(i+1,j+1,n,m,grid);
        }
        
        if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1)
        {
            return dfs(i+1,j-1,n,m,grid);
        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m,1);
        
        for(int i=0;i<m;i++)
        {
            ans[i] = dfs(0,i,n,m,grid);
        }
        
        return ans;
    }
};