class Solution 
{
    bool v[16];
    int n;
    int ans;
public:
    int countArrangement(int n) 
    {
        this->n = n;
        
        dfs(1);
        
        return ans;
    }
    
    void dfs(int c)
    {
        if (c > n)
        {
            ++ans;
            return;
        }
        
        for (int i = 1; i <= n; ++i)
        {
            if (!v[i])
            {
                if (c % i == 0 or i % c == 0)
                {
                    v[i] = 1;
                    dfs(c + 1);
                    v[i] = 0;
                }
            }
        }
    }
};