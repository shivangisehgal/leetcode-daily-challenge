//TC: O(M*N)
//SC: O(1)

//Take two rowsa at a time
//Three cases:
// 1. First row is empty => second row becomes first
// 2. second row is empty => continue
// 3. both non-empty => find number of beams. now second becomes first

class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int m = bank.size();
        int n = bank[0].size();
        
        int ans = 0;
        int countA = 0;
        int countB = 0;

        for (int j = 0; j < n; j++) 
        {
            if (bank[0][j] == '1')
                countA++;
        }
        
        for(int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                if (bank[i][j] == '1')
                    countB++;
            }
            
//             if(countA == 0) => redundant
//             {
//                 countA = countB;
//                 countB = 0;
//             }
            
            if(countB == 0)
                continue;
            
            else
            {
                ans += (countA * countB);
                countA = countB;
                countB = 0;
            }

        }
        
        return ans;
        
    }
};
