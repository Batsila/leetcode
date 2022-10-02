class Solution 
{
    int dp[123][123];
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> zos;
        
        for (string s : strs)
        {
            int z = 0;
            int o = 0;
            
            for (char c : s)
            {
                c == '1' ? ++o : ++z;
            }
            
            vector<int> zo;
            zo.push_back(z);
            zo.push_back(o);
            
            zos.push_back(zo);
        }
        
        for (vector<int> zo : zos)
        {
            for (int i = m; i >= zo[0]; --i)
            {
                for (int j = n; j >= zo[1]; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zo[0]][j - zo[1]] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};