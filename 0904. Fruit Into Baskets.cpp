class Solution
{
public:
    int totalFruit(vector<int>& f)
    {
        map<int, int> m;

        int l = 0;
        int r = 0;

        while (r < f.size())
        {
            ++m[f[r]];

            if (m.size() > 2)
            {
                --m[f[l]];

                if (m[f[l]] == 0)
                {
                    m.erase(f[l]);
                }

                ++l;
            }

            ++r;
        }

        return r - l;
    }
};