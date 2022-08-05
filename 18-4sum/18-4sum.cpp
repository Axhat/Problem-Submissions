class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        set<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(binary_search(nums.begin()+k+1,nums.end(),(long long)target-((long long)nums[i]+(long long)nums[j]+(long long)nums[k])))
                    {
                          vector<int> aux;
                          aux.push_back(target-(nums[i]+nums[j]+nums[k]));
                          aux.push_back(nums[i]);
                          aux.push_back(nums[j]);
                          aux.push_back(nums[k]);
                          
                          sort(aux.begin(),aux.end());
                                        
                          ans.insert(aux);
                                        
                    }
                }
            }
        }
                                        
        vector<vector<int>> res(ans.begin(),ans.end());
                                        
        return res;
    }
};