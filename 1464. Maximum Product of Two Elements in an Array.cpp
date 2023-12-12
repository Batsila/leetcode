class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int max = 0;
        int sec = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= max)
            {
                sec = max;
                max = nums[i];
            }
            else if (nums[i] > sec)
            {
                sec = nums[i];
            }
        }
        
        return (max - 1) * (sec - 1);
    }
};