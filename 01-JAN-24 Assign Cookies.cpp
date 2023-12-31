class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        int i = 0;
        
        for(int j = 0; j < s.size() and i < g.size(); j++)
        {
            if(s[j] >= g[i])
                i++;
        }
        
        return i;
    }
};
