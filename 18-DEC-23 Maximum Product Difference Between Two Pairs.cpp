//Brute: sort, first two ka product - last two ka product => TC: O(NlogN)
//Optimal: first max two and min two (since size >= 4, hence, max and min will never be equal) => TC: O(N)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int mini = 1e4 + 1;
        int smini = 1e4 + 1;
        
        int maxi = 0;
        int smaxi = 0;
        
        for(auto num : nums)
        {
            if(num > maxi)
            {
                smaxi = maxi;
                maxi = num;
            }
            
            else if(num > smaxi) //num == maxi
            {
                smaxi = num;
            }
            
            
            if(num < mini)
            {
                smini = mini;
                mini = num;
            }
            
            else if(num < smini)
            {
                smini = num;
            }
        }
        
        int ab = maxi * smaxi;
        int cd = mini * smini;
        
        return ab - cd;
    }
};


