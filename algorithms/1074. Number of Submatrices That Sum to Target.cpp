class Solution 
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    { 
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 1; j < matrix[0].size(); ++j)
            {
                matrix[i][j] =  matrix[i][j] + matrix[i][j -1];
            }
        }
      
        int ans = 0;
        
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            for(int j = i; j < matrix[0].size(); ++j)
            {
                unordered_map<int, int> m;
                m[0] = 1;
                
                int sum = 0;
                
                for(int k = 0; k < matrix.size(); ++k)
                {
                    sum += matrix[k][j];
                    
                    if (i)
                    {
                        sum -= matrix[k][i - 1];
                    }
                    
                    if (m.find(sum - target) != m.end())
                    {
                        ans += m[sum - target];
                    }

                    ++m[sum];
                }
            }
        }
        
        return ans;
    }
};