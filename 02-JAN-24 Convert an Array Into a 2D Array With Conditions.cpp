//Approach 1
//Use a freq map
//Create a vector of vector, of size = maxfreq.
//element will be in all vectors from 0 to freq - 1.

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int> freqMap;
        
        int maxFreq = 0;
        
        for(int num : nums)
        {
            freqMap[num]++;
            maxFreq = max(maxFreq, freqMap[num]);
        }
        
        vector<vector<int>> ans(maxFreq);
        
        for(auto el : freqMap)
        {
            int num = el.first;
            int freq = el.second;
            
            if(freq == 0)
                continue;
            
            for(int i = 0; i < freq; i++)
            {
                ans[i].push_back(num);
            }
            
            freqMap[num] = 0;
        }
        
        return ans;
    }
};

//Approach 2
//Same as above, but one pass

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        
        for(int num : nums)
        {
            freq[num]++;
            
            if(freq[num] > ans.size())
                ans.push_back({});
            
            ans[freq[num] - 1].push_back(num);
        
        }
        
        return ans;
    }
};
