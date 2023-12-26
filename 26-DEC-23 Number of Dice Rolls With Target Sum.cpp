//Memoization


class Solution {
    
    int mod = 1e9 + 7;
    
public:
    int func(int dieNum, int k, int target, vector<vector<int>>& dp)
    {
        if(dieNum == 0 && target == 0)
            return 1;
        
        else if(dieNum == 0 || target == 0)
            return 0;
        
        if(dp[dieNum][target] != -1)
            return dp[dieNum][target];
        
        int sum = 0;
        
        for(int i = 1; i <= k; i++)
        {
            if(target < i)
                break;
            
            else
                sum = (sum + func(dieNum - 1, k, target - i, dp)) % mod;
        }
        
        return dp[dieNum][target] = sum % mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return func(n, k, target, dp);
    }
};

//Memoization
class Solution {
    
    int mod = 1e9 + 7;
    
public:
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        dp[0][0] = 1;
        
        for(int dieNum = 1; dieNum <= n; dieNum++)
        {
            for(int t = 1; t <= target; t++)
            {
                int sum = 0;
                
                for(int i = 1; i <= k; i++)
                {
                    
                    if(t < i)
                        break;
                    else
                    {
                        sum = (sum + dp[dieNum - 1][t - i]) % mod;
                    }
                }
                
                dp[dieNum][t] = sum % mod;
            }
        }
        
        return dp[n][target];
    }
};

//Space Optimization
class Solution {
    
    int mod = 1e9 + 7;
    
public:
    
    int numRollsToTarget(int n, int k, int target) {
                
        vector<int> prevRow(target + 1, 0);
        
        prevRow[0] = 1;
        
        for(int dieNum = 1; dieNum <= n; dieNum++)
        {
            vector<int> currRow(target + 1, 0);
            
            for(int t = 1; t <= target; t++)
            {
                int sum = 0;
                
                for(int i = 1; i <= k; i++)
                {
                    
                    if(t < i)
                        break;
                    else
                    {
                        sum = (sum + prevRow[t - i]) % mod;
                    }
                }
                
                currRow[t] = sum % mod;
            }
            
            prevRow = currRow;
        }
        
        return prevRow[target];
    }
};
