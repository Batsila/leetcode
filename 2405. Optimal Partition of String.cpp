class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> m(26, -1);
        int ans = 1;
        int ind = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i] - 'a'] >= ind)
            {
                ++ans;
                ind = i;
            }

            m[s[i] - 'a'] = i;
        }

        return ans;
    }
};