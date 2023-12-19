class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int filterSize = 0;
                int filterSum = 0;
                
                for(int r = max(0, i - 1); r <= min(n - 1, i + 1); r++)
                {
                    for(int c = max(0, j - 1); c <= min(m - 1, j + 1); c++)
                    {
                        filterSum += img[r][c];
                        filterSize++;
                    }
                }
                
                ans[i][j] = filterSum / filterSize;
                
            }
        }
        
        return ans;
    }
};
