class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
            
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
           for(int prev_ind = i - 1; prev_ind >= -1; prev_ind--)
           {
               
                int not_take = dp[i + 1][prev_ind + 1] ;
               
                int valid = 0;
               
                int take = 0;
                
                if(prev_ind == -1 || nums[i] > nums[prev_ind])
                {
                    take = 1 + dp[i + 1][i + 1]; 
                    valid = max(not_take, take);
                }
               
                //prev index is i only, but since there is shfite of index.


                dp[i][prev_ind + 1] = max(not_take, valid);
           }
            
        }
        
        return dp[0][-1 + 1];
    }
};
