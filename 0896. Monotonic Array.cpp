class Solution
{
public:
    bool isMonotonic(vector<int>& nums)
    {
        int d = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            int cd = nums[i] - nums[i - 1];

            if (cd != 0)
            {
                cd /= abs(cd);
            }

            if (d == 0)
            {
                d = cd;
            }
            else
            {
                if (cd != 0 && cd != d)
                {
                    return false;
                }
            }
        }

        return true;
    }
};