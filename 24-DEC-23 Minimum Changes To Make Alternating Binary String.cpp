class Solution {
public:
    int minOperations(string s) {
        
        //01 or //10
        //all
        //0 1 0 1 0 1 0 1 0 1
        //1 0 1 0 1 0 1 0 1 0
        
        int countFor01 = 0;
        int countFor10 = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(i % 2 == 0)
            {
                if(s[i] == '0')
                    countFor10++; //swap to '1'
                else
                    countFor01++; //swap to '0'
            }
            
            else
            {
                if(s[i] == '0')
                    countFor01++; //swap to '1'
                else
                    countFor10++; //swap to '0'
            }
        }
        
        return min(countFor01, countFor10);
    }
};
