class Solution
{
    int a[1000];
    int b[1000];
public:
    int findJudge(int n, vector<vector<int>>& trusts)
    {
        for (auto trust : trusts)
        {
            ++a[trust[0] - 1];
            ++b[trust[1] - 1];
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 0 and b[i] == n - 1)
            {
                return i + 1;
            }
        }
        
        return -1;
    }
};