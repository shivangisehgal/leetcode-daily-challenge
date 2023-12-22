//1. Brute (Nested loop, O(N^2)
//2. Better (Prefix and Suffix)
//3. Optimal

//BETTER
//Prefix, suffix sum approach
//TC: O(N)
//SC: O(N)

//OPTIMAL
//One Pass (Important observation for binary strings)
// zeroes[i] - ones[i] + totOnes = zeroes[i] - tot(ones[i + 1]...ones[n - 1])

//TC: O(N)
//SC: O(1)

class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        
        int maxScore;
        int maxDiff = INT_MIN;
        
        int ones = 0;
        int zeroes = 0;
        
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == '0')
                zeroes++;
            else
                ones++;
            
            maxDiff = max(maxDiff, zeroes - ones);
        }
        
        if(s[n - 1] == '1')
            ones++;
        
        int totOnes = ones;
        
        maxScore = maxDiff + totOnes;
        
        return maxScore;
    }
};
