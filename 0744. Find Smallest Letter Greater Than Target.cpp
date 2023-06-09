class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int l = 0;
        int r = letters.size() - 1;
        int m = 0;

        while (l <= r)
        {
            m = (l + r) / 2;

            if (target >= letters[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return l == letters.size() ? letters[0] : letters[l];
    }
};