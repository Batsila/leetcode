class Solution
{
public:
    int minimumRounds(vector<int>& tasks)
    {
        map<int, int> m;

        for (int task : tasks)
        {
            ++m[task];
        }

        int ans = 0;

        for (auto p : m)
        {
            if (p.second == 1)
            {
                return -1;
            }

            if (p.second % 3 == 0)
            {
                ans += p.second / 3;
            }
            else
            {
                ans += p.second / 3 + 1;
            }
        }

        return ans;
    }
};