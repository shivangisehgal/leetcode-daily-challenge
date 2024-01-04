//If a number is not divisble by 3, take it to the nearest number divisible by 3, such that their difference is divisible by 2.
//Hence, if number is: 11 => (9, 2) | 16 => (12, 4)
//thus, the nearest number can be (freq / 3) * m  OR (freq / 3) * (m - 1)
//Difference of freq - 3m can also be written as freq % 3
//Hence, ans can be [ freq / 3 +  (freq % 3) / 2 ]     OR   [ freq / 3 - 1   + (freq % 3 + 3) / 2 ]

//My approach 1:
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> map;
        
        for(auto num : nums)
            map[num]++;
        
        int minWays = 0;
        
        for(auto el : map)
        {
            int num = el.first;
            int freq = el.second;
            
            if(freq < 2)
                return -1;
            
            
            if(freq % 3 == 0)
                minWays += freq / 3;
            
            else
            {
                //nearest multiple of 3, which gives remainder a multiple of 2
                int m = freq / 3;
                int mult = 3 * m;
                
                int diff = freq - mult;
                
                if(diff % 2 != 0)
                {
                    m = m - 1;
                    diff = diff + 3;
                }
                
                minWays += m + diff / 2;
            }
                            
        }
        
        return minWays;
    }
};

//Simplified approach
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> map;
        
        for(auto num : nums)
            map[num]++;
        
        int minWays = 0;
        
        for(auto el : map)
        {
            int num = el.first;
            int freq = el.second;
            
            if(freq < 2)
                return -1;
            
            
            if(freq % 3 == 0)
                minWays += freq / 3;
            
            else if(freq % 3 == 2)
            {
                 minWays += freq / 3 + (freq % 3) / 2;
            }
            
            else
            {
                minWays += freq / 3 - 1 + (freq % 3 + 3) / 2;
            }
                            
        }
        
        return minWays;
    }
};
