class Solution
{
public:
    int pivotInteger(int n)
    {
        int p = 1;

        do
        {
            int lSum = p == 1 ? 1 : (1 + p) * p / 2;
            int rSum = p == n ? n : (p + n) * (n - p + 1) / 2;

            if (lSum == rSum)
            {
                return p;
            }

            ++p;
        }
        while (p < n);

        return -1;

    }
};