class Solution {
public:
    
    float findSlope(int x1,int y1,int x2,int y2)
    {
        if(x2-x1==0) return 1e9;
        
        
        float slope = (float) (y2-y1) / (float) (x2-x1);
        
        return slope;
    }
    
    
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int currMax = 0;
        
        for(int i=0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            unordered_map<float,int> slopeRecord;
            
            for(int j=i+1;j<n;j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                float slope = findSlope(x1,y1,x2,y2);
                
                slopeRecord[slope]++;
                currMax = max(currMax,slopeRecord[slope]);
            }
        }
        
        return currMax+1;
    }
};