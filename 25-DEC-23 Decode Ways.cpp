//Memoization
class Solution {
public:
    
    int func(int i, string s, vector<int>& dp)
    {
        if(i > s.length())
            return 0;
        
        if(i == s.length())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int l = 0, r = 0;
        
        if(s[i] == '1')
            r = func(i + 2, s, dp);
        
        else if(s[i] == '2')
        {
            if(i < s.length() - 1 && s[i + 1] <= '6')
                r = func(i + 2, s, dp);
        }
        
        l = func(i + 1, s, dp);
        
        return dp[i] = l + r;
    }
    
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n + 2, -1);
        return func(0, s, dp);
    }
};

//Tabulation
class Solution {
public:
    
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n + 2, 0);
        
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int l = 0;
            int r = 0;
            
            if(s[i] == '0')
                continue;
            
            l = dp[i + 1];
            
            if(s[i] == '1' || (s[i] == '2' && i < n - 1 && s[i + 1] <= '6'))
                r = dp[i + 2];
            
            dp[i] = l + r;
            
        }
        
        return dp[0];
    }
};
