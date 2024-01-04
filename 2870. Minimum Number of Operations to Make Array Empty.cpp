class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        unordered_map<int, int> m;

        for (int num : nums)
        {
            m[num]++;
        }

        int ans = 0;

        for (auto p : m)
        {
            int n = p.second;

            if (n == 1)
            {
                return -1;
            }

            if (n % 3 == 0)
            {
                ans += n / 3;
            }
            else
            {
                ans += n / 3 + 1;
            }
        }

        return ans;
    }
};