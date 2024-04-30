class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<int, int> frequencies;
        int mask = 0;
        frequencies[mask] = 1;
        long long ans = 0;

        for (char c : word)
        {
            mask ^= 1 << (c - 'a');
            ans += frequencies[mask];
            ++frequencies[mask];

            for (int i = 0; i < 10; ++i)
            {
                ans += frequencies[mask ^ (1 << i)];
            }
        }

        return ans;
    }
};