class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for (int i = 1; i <= s.length() / 2; ++i)
        {
            if (s.length() % i == 0)
            {
                string p = s.substr(0, i);
                string t = "";

                while (t.length() < s.length())
                {
                    t += p;
                }

                if (t == s)
                {
                    return true;
                }
            }
        }

        return false;
    }
};