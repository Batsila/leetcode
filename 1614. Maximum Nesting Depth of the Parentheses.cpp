class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int current_count = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                ++current_count;
            }
            else if (c == ')')
            {
                ans = max(ans, current_count);
                --current_count;
            }
        }

        return ans;
    }
};