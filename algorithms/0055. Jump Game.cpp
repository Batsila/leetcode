class Solution 
{
    bool u[30000];
    vector<int> v;
public:
    bool canJump(vector<int>& nums) 
    {
        v = nums;
        
        dfs(0);
        
        return u[nums.size() - 1];
    }
    
    void dfs(int c)
    {
        u[c] = true;
        
        for (int i = 1; i <= v[c]; ++i)
        {
            if (c + i < v.size() && !u[c + i])
            {
                dfs(c + i);
            }
        }
    }
};