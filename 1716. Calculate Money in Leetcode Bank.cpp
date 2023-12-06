class Solution
{
public:
    int totalMoney(int n)
    {
        int ans = 0;
        int c = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i % 7 == 0)
            {
                c = i / 7 + 1;
            }
            else
            {
                ++c;
            }

            ans += c;
        }

        return ans;
    }
};