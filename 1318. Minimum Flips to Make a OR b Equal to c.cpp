class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;

        while (a != 0 or b != 0 or c != 0)
        {
            if (c & 1)
            {
                if (not (a & 1) and not (b & 1))
                {
                    ++ans;
                }
            }
            else
            {
                if (a & 1)
                {
                    ++ans;
                }

                if (b & 1)
                {
                    ++ans;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};