class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        if (nums.size() >= 3)
        {
            int a = INT_MAX;
            int b = INT_MAX;
            
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] > b)
                {
                    return true;
                }
                else if (nums[i] > a and nums[i] < b)
                {
                    b = nums[i];
                }
                else if (nums[i] < a)
                {
                    a = nums[i];
                }
            }
        }
        
        return false;
    }
};