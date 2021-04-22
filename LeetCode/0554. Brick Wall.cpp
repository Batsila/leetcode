class Solution 
{
    unordered_map<int, int> m;
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        int ans = 0;
        
        for (vector<int> row : wall)
        {
            int pos = 0;
            for (int i = 0; i < row.size() - 1; ++i)
            {
                pos += row[i];
                
                int n = 1;
                
                auto ind = m.find(pos);
                if (ind != m.end())
                {
                    n += ind->second;
                }

                m.insert_or_assign(pos, n);
                ans = max(ans, n);
            }
        }
        
        return wall.size() - ans;
    }
};