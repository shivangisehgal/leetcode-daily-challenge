class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int mini = INT_MAX;
        int smini = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < mini)
            {
                smini = mini;
                mini = prices[i];
            }
            
            else if(prices[i] < smini)
                smini = prices[i];
        }
        
        int sum = mini + smini;
        
        return sum > money ? money : money - sum;
    }
};
